*This project has been created as part of the 42 curriculum by lfedal, obohbot.*

# push_swap

## Description

`push_swap` sorts a list of integers using two stacks, **a** and **b**, and a limited set of 11 operations. The program does not sort "in memory": it **computes and prints** the sequence of operations that sorts stack **a** (smallest number on top), trying to use as few operations as possible.

The educational goal of the project is to make **algorithmic complexity** tangible. The complexity of each strategy is measured in **number of push_swap operations generated**, not in CPU time.

The program embeds **four strategies**, selected at runtime:

| Flag | Strategy | Algorithm | Complexity (operations) |
|---|---|---|---|
| `--simple` | Simple | Turk (cheapest insertion) | O(n²) |
| `--medium` | Medium | Chunk sort (√n groups) | O(n√n) |
| `--complex` | Complex | LSD radix sort on ranks | O(n log n) |
| `--adaptive` (default) | Adaptive | chosen from the measured disorder | O(n²) / O(n√n) / O(n log n) |

### The operations

| Operation | Effect |
|---|---|
| `sa` / `sb` | swap the first two elements of a / of b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | take the top of b and put it on top of a |
| `pb` | take the top of a and put it on top of b |
| `ra` / `rb` | the first element of a / of b becomes the last one |
| `rr` | `ra` and `rb` at the same time |
| `rra` / `rrb` | the last element of a / of b becomes the first one |
| `rrr` | `rra` and `rrb` at the same time |

---

## Instructions

### Compilation

```bash
make        # builds ft_printf, then push_swap
make clean  # removes object files
make fclean # also removes the executable and libftprintf.a
make re     # fclean then all
```

Compiled with `cc -Wall -Wextra -Werror`. The Makefile does not relink unnecessarily.

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <numbers...>
```

- The first number is the **top** of stack a.
- Numbers can be given as separate arguments (`3 2 1`) or in a single string (`"3 2 1"`).
- Flags can be placed anywhere among the arguments.
- If no strategy is given, `--adaptive` is used.
- With no argument, or if the stack is already sorted, nothing is printed.

### Examples

```bash
$ ./push_swap 2 1 3 6 5 8
pb
pb
rb
pb
sa
pa
pa
pa

$ ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK

$ shuf -i 0-9999 -n 500 > args.txt; ./push_swap $(cat args.txt) | wc -l

$ ./push_swap 1 abc
Error
```

### Benchmark mode

`--bench` prints statistics **on standard error** (stderr) after sorting. The operation list stays alone on standard output, so it can still be piped into the checker.

```bash
$ ./push_swap --bench 3 1 2 5 4 7 6 > /dev/null
[bench] disorder: 19.05%
[bench] strategy: Adaptive / O(n²)
[bench] total_ops: 13
[bench] sa: 1 sb: 0 ss: 0 pa: 4 pb: 4
[bench] ra: 2 rb: 0 rr: 0 rra: 1 rrb: 1 rrr: 0
```

### Error handling

The program prints `Error` followed by a newline **on stderr**, frees all memory and exits with status 1 when:

- an argument is not an integer (`abc`, `12a`, `""`, `-`, `+`, `--5`, `+-5`, `" 5"`…);
- an integer is outside the `int` range (`2147483648`, `-2147483649`…);
- a value appears twice (`1 2 1`, but also `0 -0` or `5 +5`, because values are compared, not text);
- a flag is unknown (`--fast`, `--`);
- two strategies are requested at once (`--simple --complex`), or `--bench` is given twice.

---

## Project structure

### Directory layout

```
.
├── Makefile
├── README.md
├── includes/
│   └── push_swap.h            single header: structures, constants, all prototypes
├── ft_printf/                 our own ft_printf (the only output function allowed besides write)
└── srcs/
    ├── main.c                 entry point: parse → measure disorder → sort → bench → free
    ├── push_swap.c            choose_methode(): picks the strategy
    ├── disorder.c             comp_disorder(): disorder metric
    ├── parser/
    │   ├── parse.c            number validation, int overflow, duplicates, error_exit()
    │   ├── parse_flag.c       ft_strcmp, is_flag, parse_flag (strategy and --bench flags)
    │   ├── parse_args.c       build_stack(): loops over argv, splits "3 2 1" strings
    │   ├── benchmark.c        bench(): prints the --bench report on stderr
    │   └── bench_utils.c      init_stats, ft_putstr_fd, ft_putnbr_fd, ft_strlcpy
    ├── opperations/
    │   ├── opp_s.c            sa, sb, ss
    │   ├── opp_p.c            pa, pb
    │   ├── opp_r.c            ra, rb, rr
    │   └── opp_rr.c           rra, rrb, rrr
    ├── algorithme/
    │   ├── turk.c, turk_bis.c Turk algorithm (simple strategy)
    │   ├── chunk.c            chunk sort (medium strategy)
    │   ├── radix.c            radix sort (complex strategy)
    │   └── mini_push.c        small stacks, 2 to 5 elements (adaptive)
    └── utils/
        ├── utils.c            node creation, add front/back, last node, ft_strlen
        ├── utils_1.c          free_stack, pop front/back, set_index, stack_len
        ├── utils_2.c          find_min, find_max, find_target_b, min_int, sort_three
        ├── utils_3.c          ft_split, value_to_rank (rank normalization)
        └── utils_cost.c       move cost computation for Turk
```

The code is split by **responsibility**: parsing, operations, algorithms and shared tools each have their own folder. This let us work in parallel on different files, and keeps every file within the Norm (25 lines per function, 5 functions per file).

### Data structures

**`t_node`**: one element of a stack. Both stacks are **doubly linked lists**: `pop` and `push` at the top, and moving the first element to the bottom (`ra`) or the last to the top (`rra`), are simple pointer changes.

```c
typedef struct s_node
{
	int				value;    // the number (replaced by its rank before sorting)
	int				index;    // current position in the stack (set_index)
	int				cost;     // move cost (Turk)
	bool			abv_med;  // true if in the upper half: rotate up, else down
	bool			chpst;    // "cheapest" marker (Turk)
	struct s_node	*target;  // target node in the other stack (Turk)
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;
```

**`t_opts`**: what the user asked for, filled by the parser and read by `choose_methode`.

```c
typedef struct s_opts
{
	int	strategy;   // STRAT_SIMPLE, STRAT_MEDIUM, STRAT_COMPLEX or STRAT_ADAPTIVE
	int	bench;      // 1 if --bench was given
}	t_opts;
```

**`t_stats`**: one counter per operation, used by `--bench`. Global variables are forbidden, so every operation receives a `t_stats *` and increments its own counter: `sa(&a, &s)`, `pb(&b, &a, &s)`…

### Program flow

```
argv
  │
  ▼
build_stack ─── each argument: flag? → parse_flag → t_opts
  │                            number? → is_valid_number → str_to_int → is_double → new node
  │             any error → error_exit: free, "Error" on stderr, exit(1)
  ▼
comp_disorder ─ measured BEFORE any move
  │
  ▼
choose_methode ─ disorder = 0 → nothing to do
  │              otherwise → turk / chunk_sort / radix / sort_small
  ▼
bench ───────── only with --bench, on stderr
  │
  ▼
free_stack
```

---

## Shared building blocks

### Rank normalization

Before sorting, the medium and complex algorithms replace every value with its **rank**: 0 for the smallest, n-1 for the largest. For example, `[42, -7, 1000, 3]` becomes `[2, 0, 3, 1]`. Relative order does not change, but negative numbers and very large values disappear. This is **essential for radix sort**, which works on the bits of the numbers.

`value_to_rank` first computes every rank into the `index` field, then copies them into `value` in a second pass. Writing the ranks directly into `value` would make the next nodes compare themselves to already-modified values: this was a real bug we found and fixed (`[8, 10, 4]` gave the ranks `[1, 2, 2]`).

### Disorder metric

Disorder is a number between 0 and 1. We look at every pair of elements `(i, j)` with `i` above `j` in the stack, and count the pairs in the wrong order (`a[i] > a[j]`):

```
disorder = pairs in the wrong order / total number of pairs
```

0 means already sorted, 1 means sorted in reverse. It is the proportion of **inversions** in the sequence, and it is measured **before** any move.

### Shortest rotation

Several algorithms need to bring a given node to the top of a stack. `set_index` marks each node as being in the upper or lower half (`abv_med`). If the node is in the upper half, we rotate up (`ra`/`rb`); otherwise we rotate down (`rra`/`rrb`). We never need more than n/2 rotations.

---

## Algorithms

### Simple: Turk, O(n²)

**Idea:** move the elements of a to b, each time choosing **the one that costs the fewest moves** to place, while keeping b sorted in descending order. Then bring everything back to a.

1. If a holds more than 3 elements, two `pb` to seed b.
2. While a holds more than 3 elements:
   - for each element of a, find its **target** in b: the largest element of b that is smaller than it, or the maximum of b if there is none;
   - compute the **cost** to bring the element to the top of a and its target to the top of b, using `rr` / `rrr` when both stacks rotate in the same direction;
   - perform the rotations of the cheapest element, then `pb`.
3. Sort the 3 remaining elements of a (2 moves at most).
4. Bring every element of b back to its place in a, then rotate a so the minimum is on top.

**Complexity:** each element moves once to b and once back to a. Placing it costs at worst about n rotations, so the number of operations is bounded by **O(n²)**. In practice, always choosing the cheapest move makes it much better than this bound. Measured on our program (10 runs): about **560 operations for 100 numbers** and **5,100 for 500** on random input, and about 250 and 1,800 on nearly sorted stacks (around 5% disorder).

**Memory:** O(1) besides the two stacks (`index`, `cost`, `target` fields in each node).

### Medium: chunk sort, O(n√n)

**Idea:** split the ranks into groups (*chunks*) of size k = ⌊√n⌋, push the groups to b one after the other, then always bring back the largest element of b.

1. Rank normalization, then k = ⌊√n⌋ (integer square root computed by hand, without `<math.h>`).
2. **Phase 1, a to b:** for the group of ranks `[low, low + k - 1]`, look at the top of a: if it belongs to the group, `pb`, otherwise `ra`. Once every element of the group is in b, move on to the next group.
3. **Phase 2, b to a:** while b is not empty, find the maximum of b, bring it up by the shortest path (`rb` or `rrb`), then `pa`. The largest arrives first, so a is rebuilt in order.

**Complexity:**
- Phase 1: there are about √n groups, and each one costs at most one full turn of a (n operations). Total: about **n√n**.
- Phase 2: b is organized by groups, largest on top. The remaining maximum is always within about one group (√n positions) of the top, in one direction or the other. Total: about **n√n**.

Number of operations: **O(n√n)**. Measured: about **810 to 870 operations for 100 numbers** and about **8,250 for 500**.

**Memory:** O(1) besides the stacks.

### Complex: LSD radix sort on ranks, O(n log n)

**Idea:** sort the ranks **bit by bit**, from the least significant bit to the most significant one. For each bit, every element is looked at exactly once: bit set to 1, it stays in a (`ra`); bit set to 0, it goes to b (`pb`). Then everything comes back from b to a (`pa`). Relative order is preserved at each pass (stable sort), so after the last bit, a is sorted.

1. Rank normalization (0 to n-1).
2. Number of bits: the smallest `b` such that `(n - 1) >> b == 0`.
3. For each bit: n times `ra` or `pb` depending on `(value >> bit) & 1`, then `pa` until b is empty.

**Complexity:** there are ⌈log₂ n⌉ passes, each costing at most 2n operations. Total: at most **2n·log₂ n**, which is **O(n log n)**. This bound is exact and guaranteed, whatever the starting order. Since ranks are always 0 to n-1, the operation count only depends on n: **1,084 for 100 numbers** and **6,784 for 500**.

**Memory:** O(1) besides the stacks.

### Small stacks (2 to 5 elements)

In adaptive mode, stacks of 5 elements or fewer are handled separately:
- 2 elements: one `sa`;
- 3 elements: `sort_three`, a table of the 6 possible cases (2 moves at most);
- 4 or 5 elements: push the minimum to b by the shortest path until 3 are left, sort those 3, then `pa`.

Tested on **every permutation**: at worst **2 moves for 3 elements** and **10 moves for 5 elements**.

The `--simple`, `--medium` and `--complex` flags **force** their algorithm whatever the input size, as the subject requires. This small-stack handling only applies in adaptive mode.

---

## Adaptive strategy

| Situation | Method | Complexity |
|---|---|---|
| already sorted (disorder = 0) | nothing | 0 operations |
| n ≤ 5 | small stacks | constant |
| disorder < 0.2 | Turk | O(n²) |
| 0.2 ≤ disorder < 0.5 | chunks | O(n√n) |
| disorder ≥ 0.5 | radix | O(n log n) |

### Rationale for the thresholds

The 0.2 and 0.5 thresholds, and the complexity class of each regime, are **set by the subject**. Our choices are about which method runs in each regime:

- **Low disorder (< 0.2) → Turk.** The stack is almost sorted: most elements are already close to their place, and Turk, which always takes the cheapest move, benefits fully from it (about 250 operations for 100 numbers and 1,800 for 500 at around 5% disorder). Its O(n²) bound matches the class required for this regime.
- **Medium disorder (0.2 to 0.5) → chunks.** Splitting into √n groups gives a guaranteed O(n√n) bound, as required, and stays under the subject's limits.
- **High disorder (≥ 0.5) → radix.** The subject requires O(n log n) here. Radix is the only one of our algorithms whose O(n log n) bound is **proven** and independent of the starting order. It does not take advantage of partial order, but at high disorder there is hardly any to exploit.
- **n ≤ 5 → small stacks.** For a handful of elements, hand-written cases need far fewer moves than any general algorithm.

### Bounds (time and space, push_swap model)

- Operations: O(n²) below 0.2; O(n√n) between 0.2 and 0.5; O(n log n) above; constant for n ≤ 5.
- Internal computation (not operations): at most O(n²) comparisons (disorder metric, rank normalization, Turk costs), about 250,000 for 500 numbers, which is negligible.
- Memory: O(n) for the two stacks (doubly linked lists), O(1) extra for each algorithm.

---

## Measured performance

| Strategy | 100 numbers | 500 numbers |
|---|---|---|
| Simple (Turk) | ≈ 560 | ≈ 5,100 |
| Medium (chunks) | ≈ 810 to 870 | ≈ 8,250 |
| Complex (radix) | 1,084 | 6,784 |
| Adaptive, random input (disorder ≈ 50%) | ≈ 820–870 (chunks) or 1,084 (radix) | ≈ 8,250 (chunks) or 6,784 (radix) |

Subject limits to pass: fewer than 2,000 operations for 100 numbers and fewer than 12,000 for 500.

---

## Teamwork with Git and GitHub

### How we worked

This was our first group project, and our first time using Git **collaboratively**. Before push_swap, we only knew how to `pull` and `push` on a single branch. We had to learn a real team workflow:

1. **`master` always stays compilable.** Nobody works directly on it.
2. **One branch per feature.** Each of us created a branch from an up-to-date `master` (`git checkout -b <name>`) and committed there in small steps.
3. **Pull Requests to merge.** When a feature worked, we pushed the branch and opened a Pull Request on GitHub. The other person read the code before merging it into `master`.
4. **Sync often.** After every merge, both of us ran `git pull` on `master`, and merged `master` into our current branch when needed (`git merge master`).

Branches we used during the project:

| Branch | Content |
|---|---|
| `dev_algo_0` | linked list, operations, first version of Turk |
| `parsing` | number validation, flags, error handling |
| `algo-lis` | an LIS-based algorithm we explored, then set aside |
| `algo_radx` | radix sort and the `value_to_rank` fix |
| `algo_chunk` | chunk sort |
| `sort_small` | small stacks in adaptive mode |

### What we found difficult, and why

**Git itself.** Working on the same project at the same time from two computers raised problems we had never met alone:
- **A nested repository.** Our `ft_printf` folder still contained its own `.git`, so Git stored it as a link to another repository instead of real files. On a fresh clone, the folder was empty and the project did not compile. We had to remove the inner `.git` and add the files again.
- **Generated files in commits.** A `git add .` once added `.o` files and the binary. We learned to add files one by one, to check `git status` before every commit, to fix a commit that was not pushed yet with `git commit --amend`, and to use a `.gitignore`.
- **Conflicts on shared files.** The 42 header updates its `Updated:` and `By:` lines every time a file is saved, so simply opening and saving `push_swap.h` created conflicts. We agreed to warn each other before editing shared files such as the header and the Makefile.
- **Renaming and file names.** A typo in a file name (`radx.c` instead of `radix.c`) broke the Makefile. We learned `git mv` to rename files cleanly.
- **Merging in the right order.** Some branches depended on others (the chunk sort needed the `value_to_rank` fix from the radix branch). We had to think about which branch to start from and in which order to merge.

**Integration between our parts.** Each of us wrote code that the other had to call. We had to agree on shared interfaces before writing the algorithms: the `t_opts` structure filled by the parser, the `t_stats` counters needed by `--bench` (which changed the signature of every operation), and the header that every file depends on.

**The subject's complexity requirements.** Our first algorithm choices (Turk, then an LIS-based insertion) give excellent operation counts, but their O(n log n) or O(n√n) behavior is only observed in practice, not proven. Since the subject requires a complexity class that we can **justify** for each strategy, we added radix sort and chunk sort, whose bounds can be proven, and kept Turk for the O(n²) regime.

**Linked lists and pointers in C.** Telling apart `a` (the address of the stack), `*a` (the top node) and `(*a)->value` (its number) caused several bugs: infinite loops, wrong arguments passed to operations, and nodes compared instead of values.

---

## Contributions

**obohbot**
- Stack structure (doubly linked list) and the 11 operations
- ft_printf integration, Makefile and directory organization
- Disorder metric (`disorder.c`)
- **Turk** algorithm (simple strategy) and its cost functions
- `--bench` mode and operation counting (`t_stats`)
- Numbers given as a single string (`"3 2 1"`) with `ft_split`
- Written explanation of the candidate algorithms, which guided our choices

**lfedal**
- **Parsing**: number validation, `int` overflow detection, duplicate detection, `Error` on stderr
- **Flags**: `--simple`, `--medium`, `--complex`, `--adaptive`, `--bench`, and their error rules
- **Radix** algorithm (complex strategy)
- **Chunk** algorithm (medium strategy)
- **Small stacks** (2 to 5 elements) in adaptive mode
- Fix of the rank normalization (`value_to_rank`)
- Tests of the parsing and the algorithms

Both of us reviewed each other's code and can explain every part of the project.

---

## Resources

### References

- The 42 push_swap subject.
- Wikipedia, [Radix sort](https://en.wikipedia.org/wiki/Radix_sort): radix sort, LSD variant.
- Wikipedia, [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort): splitting into groups, the basis of chunk sort.
- Wikipedia, [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort) and [Selection sort](https://en.wikipedia.org/wiki/Selection_sort): reference O(n²) sorts.
- Wikipedia, [Longest increasing subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence): the LIS approach we explored.
- Wikipedia, [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation): complexity notation.
- Wikipedia, [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)): inversions, on which our disorder metric is based.
- Wikipedia, [Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list): the structure used for the stacks.
- YouTube videos explaining push_swap and the Turk algorithm.
- Discussions with other 42 Lausanne students: sorting strategies, parsing edge cases, defense tests.
- Community testers (ft_ps tester) and public push_swap repositories, to understand the expected performance thresholds.
- Git and GitHub documentation on branches and Pull Requests.

### Use of AI

We used an AI assistant (Claude, by Anthropic) as a **tutor**, not as a generator of the submitted code:

- **Explaining concepts**: linked lists, pointers (`a`, `*a`, `(*a)->value`), bitwise operators, `int` overflow, output parameters, `exit`, stderr, algorithmic complexity.
- **Explaining algorithms**: the principles of Turk, radix sort, chunk sort and small-stack sorting, with step-by-step worked examples.
- **Reviewing code we wrote**: the AI pointed out mistakes (uninitialized variables, wrong operation arguments, infinite loops, Norm errors) without rewriting our functions for us.
- **Debugging**: testing with the AI is how we found the `value_to_rank` bug, which modified values while computing ranks.
- **Testing**: suggested test cases, simulations of operation counts, temporary test `main` functions (not submitted).
- **Git**: learning to work as a pair with branches and Pull Requests.
- **Documentation**: the written explanation of the algorithms and a first draft of this README were produced with the AI, then reviewed and completed by us.