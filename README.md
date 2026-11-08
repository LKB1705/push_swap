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
| `parser/test_parse.c` | `main` de test, **ne fait pas partie du rendu** |
| `parser/test_parse.sh` | script qui lance tous les tests, **ne fait pas partie du rendu** |

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
| `t_node *build_stack(int argc, char **argv, t_opts *opts)` | Boucle sur les arguments. Chaque argument est aiguillé avec `is_flag` : un flag va dans `parse_flag`, sinon c'est un nombre, qui passe les vérifications ci-dessus puis est ajouté à la pile avec `ft_lstnew` + `ft_lstadd_back`. Après la boucle, si aucune stratégie n'a été donnée, elle met `STRAT_ADAPTIVE`. | la pile `a` (`NULL` si aucun nombre) |

**Comment l'appeler :**

```c
t_node	*a;
t_opts	opts;

opts.strategy = STRAT_NONE;
opts.bench = 0;
a = build_stack(argc, argv, &opts);
// ici : a est valide, opts.strategy vaut 1 à 4, opts.bench vaut 0 ou 1
```

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

### Tester le parsing

`parse.c` contient un `main` de test **à supprimer avant le rendu**.
Il appelle `build_stack`, puis affiche ce que le parsing a compris :

```
strat=<stratégie> bench=<0 ou 1> | pile a : <nombres du haut vers le bas>
```

Stratégies : `1` simple, `2` medium, `3` complex, `4` adaptive (par défaut).
Si un argument est invalide, on ne voit que `Error` (sur stderr).

Compiler depuis `parser/` :

```bash
cc -Wall -Wextra -Werror parse.c parse_flag.c ../utils.c ../utils_bis.c ../ft_printf/libftprintf.a -o test_parser
```

Exemples :

```bash
./test_parser --simple 3 2 1    # strat=1 bench=0 | pile a : 3 2 1
./test_parser 3 --bench 2 1     # strat=4 bench=1 | pile a : 3 2 1
./test_parser 4 8 4             # Error
```
---

## 6. Ce qu'il reste à faire

- [x] **Brancher les flags dans `build_stack`.**
- [x] **Stratégie par défaut :** `STRAT_ADAPTIVE` si aucune n'est donnée.
- [ ] **Mise à la Norme :** `build_stack` dépasse 25 lignes (la partie « nombre » sera extraite dans une fonction à part), et indentation de `parse.c`.
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
5. **Le champ `index` des nœuds.** `build_stack` appelle `ft_lstnew(value, i, &a)` avec `i` = la position dans `argv`. Avec des flags, les index sont donc décalés : `--simple 3 2` donne les index 1 et 2 au lieu de 0 et 1. Il faut appeler `set_index` avant les algos, ou passer un compteur qui ignore les flags.
