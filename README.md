# Parsing — branche `parsing`

Ce document explique la partie **parsing** de push_swap : ce qui est fait, comment ça marche, et ce qu'il reste à décider ensemble pour l'intégrer à `master`.

Auteur de cette partie : **lfedal**

---

## 1. Rôle du parsing

Le parsing est la porte d'entrée du programme. Il transforme les arguments tapés par l'utilisateur (du texte) en :

- une **pile `a`** propre, avec uniquement des `int` valides et sans doublon ;
- un **ticket d'options `t_opts`**, qui contient la stratégie choisie et indique si `--bench` est activé.

Si un seul argument est invalide, le programme affiche `Error\n` sur **stderr**, libère la mémoire et quitte avec le code `1`.

Les algos de tri n'ont donc **rien à vérifier** : ils reçoivent une pile `a` garantie valide et un `t_opts` rempli.

```
./push_swap --bench 3 -2 15
        │
        ▼
   build_stack ──► pile a : [3] → [-2] → [15] → NULL
        │
        └────────► t_opts  : strategy = ADAPTIVE, bench = 1
```

---

## 2. Organisation des fichiers

| Fichier | Fonctions |
|---|---|
| `parser/parse.c` | `is_valid_number`, `str_to_int`, `is_double`, `error_exit`, `build_stack` |
| `parser/parse_flag.c` | `ft_strcmp`, `is_flag`, `parse_flag` |

Chaque fichier contient 5 fonctions au maximum (Norme).

### Ajouts dans `push_swap.h`

```c
# include <limits.h>   // INT_MAX, INT_MIN
# include <unistd.h>   // write

# define STRAT_NONE		0
# define STRAT_SIMPLE	1
# define STRAT_MEDIUM	2
# define STRAT_COMPLEX	3
# define STRAT_ADAPTIVE	4

typedef struct s_opts
{
	int	strategy;   // une des valeurs STRAT_*
	int	bench;      // 1 si --bench, 0 sinon
}	t_opts;
```

Les prototypes des fonctions du parser sont aussi déclarés dans le header, dans les sections `/* parser/parse.c */` et `/* parser/parse_flag.c */`.

---

## 3. Les fonctions

### Vérification des nombres — `parse.c`

| Fonction | Rôle | Retour |
|---|---|---|
| `int is_valid_number(char *s)` | Vérifie le **format** : un `+` ou `-` optionnel, puis au moins un chiffre, et uniquement des chiffres. | `1` valide, `0` invalide |
| `int str_to_int(char *s, int *out)` | Convertit en `int`. Le calcul se fait dans un `long`, avec une vérification **à chaque chiffre** contre `INT_MAX` / `INT_MIN`. Le résultat est écrit dans `*out`. | `1` ok, `0` dépassement |
| `int is_double(t_node *a, int value)` | Parcourt la pile pour voir si `value` y est déjà. | `1` doublon, `0` sinon |
| `void error_exit(t_node **a)` | Libère la pile, écrit `Error\n` sur stderr (`write(2, ...)`), puis `exit(1)`. | — |
| `t_node *build_stack(int argc, char **argv)` | Boucle sur les arguments, applique les vérifications ci-dessus et construit la pile avec `ft_lstnew` + `ft_lstadd_back`. | la pile `a` |

**Pourquoi `str_to_int` est appelée seulement après `is_valid_number` :** la conversion suppose que le texte est bien formé. L'ordre des vérifications est donc important, et le court-circuit du `||` le garantit.

**Pourquoi comparer les valeurs (`int`) et pas le texte pour les doublons :** `5`, `+5` et `005` sont trois textes différents mais une seule valeur. De même, `0` et `-0` sont bien détectés comme doublons.

### Flags — `parse_flag.c`

| Fonction | Rôle | Retour |
|---|---|---|
| `int ft_strcmp(char *s1, char *s2)` | Comparaison classique, caractère par caractère, jusqu'au `'\0'`. | `0` si identiques |
| `int is_flag(char *s)` | Dit si l'argument commence par `--`. Un seul `-` désigne un nombre négatif, pas un flag. | `1` flag, `0` sinon |
| `int parse_flag(char *s, t_opts *opts)` | Reconnaît le flag et remplit `opts`. | `1` ok, `0` erreur |

---

## 4. Règles choisies pour les flags (à valider ensemble)

| Règle | Exemple | Résultat |
|---|---|---|
| Un flag peut être placé n'importe où | `3 --simple 2 1` | OK |
| Une seule stratégie | `--simple --complex 1 2` | Error |
| `--bench` une seule fois | `--bench --bench 1` | Error |
| Flag inconnu | `--fast 1 2`, `-- 1 2` | Error |
| Aucune stratégie donnée | `3 2 1` | `--adaptive` par défaut |
| `--bench` combinable avec une stratégie | `--simple --bench 3 2 1` | OK |

---

## 5. Tests réalisés

Les tests ont été faits avec un `main` de test (non commité) et `valgrind --leak-check=full`.

| Entrée | Attendu | ✔ |
|---|---|---|
| `4 8 15 -16 23 42` | pile `4 8 15 -16 23 42` | ✅ |
| *(aucun argument)* | pile vide, rien affiché | ✅ |
| `2147483647 -2147483648` | acceptés (limites exactes) | ✅ |
| `007`, `+3` | `7`, `3` | ✅ |
| `2147483648`, `-2147483649`, `99999999999999999999` | Error | ✅ |
| `abc`, `12a`, `""`, `-`, `+`, `--5`, `+-5`, `" 5"` | Error | ✅ |
| `4 8 4`, `0 -0`, `5 +5` | Error (doublon) | ✅ |
| `1 abc 2>/dev/null` | rien sur stdout, code de sortie `1` | ✅ |
| Fuites mémoire, y compris en cas d'erreur | aucune | ✅ |
| `parse_flag` : `--simple`, `--bench`, puis `--complex`, `--bench`, `--fast` | `1 1 0 0 0`, strategy = SIMPLE, bench = 1 | ✅ |

Pour compiler le test depuis `parser/` :

```bash
cc -Wall -Wextra -Werror parse.c parse_flag.c ../utils.c ../utils_bis.c ../ft_printf/libftprintf.a -o test_parser
```

---

## 6. Ce qu'il reste à faire

- [ ] **Brancher les flags dans `build_stack`.** Elle recevra `t_opts *opts`, et chaque argument sera aiguillé avec `is_flag` : vers `parse_flag` si c'est un flag, vers les vérifications de nombre sinon.
- [ ] **Stratégie par défaut :** si `opts->strategy == STRAT_NONE` à la fin, mettre `STRAT_ADAPTIVE`.
- [ ] **Remplacer `create_stack_a` par `build_stack`** dans `push_swap.c`, car `create_stack_a` ne vérifie rien.
- [ ] **Ajouter `parser/parse.c` et `parser/parse_flag.c` au Makefile.**
- [ ] **Calcul du désordre**, à partir de la pile `a`.

---

## 7. Questions à décider ensemble

1. **Structure commune `t_ps`.** Proposition : elle contient les deux piles, le `t_opts` et les compteurs d'opérations.
   ```c
   typedef struct s_ps
   {
   	t_node	*a;
   	t_node	*b;
   	t_opts	opts;
   	int		count[11];   // un compteur par opération, pour --bench
   }	t_ps;
   ```
2. **Compter les opérations pour `--bench`.** Les variables globales sont interdites, donc les opérations doivent recevoir `t_ps *` : `sa(t_ps *ps)` au lieu de `sa(t_node **a)`. Ce changement touche tous les fichiers `opp_*.c`, il vaut mieux le faire **avant** d'écrire les algos.
3. **Les règles des flags** de la section 4 : est-ce qu'elles te conviennent ?
4. **Conflits de noms avec la libft.** Si on ajoute une libft un jour, `ft_lstnew`, `ft_lstlast`, `ft_lstadd_front`, `ft_lstadd_back` et `ft_atoi` existent déjà avec d'autres types. Il faudrait alors les renommer (`node_new`, `node_last`…).


---
