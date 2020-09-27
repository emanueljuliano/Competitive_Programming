
/*

   The first trick is to see that the binary representation of N(t) is
   a prefix representation of the tree t. Hence N^{-1} is parsing
   while N is pretty printing. The two trees from the task are
   represented in binary as 10100 and 11000 respectively.

   I. The successor function --- canonical implementation
   =======================================================

   The successor function can be coded recursively on trees.  Before
   describing it, notice that the minimal tree is a right-branching
   list-like tree and the maximal tree is a left-branching list-like
   tree.

                       *                    *
                      / \                  / \
                    .*   o                o   *.
                   .  \                      /  .
                  .    o                    o    .
                 .                                .
                *                                  *
               / \                                / \
              o   o                              o   o

                 maximal                     minimal


   To define the successor in B(n) we need two auxiliary functions:

   1) succ_gt - successor in B (with more nodes)

   Given a tree t with n nodes, its successor in the set of all binary
   trees B always exists and can be obtained by replacing the
   rightmost leaf by a node with two leafs.  Hence the successor of t
   has n+2 nodes.

   2) succ_le - successor in B(<=n) (with less or equal nodes)

   Given a tree t with n nodes, its successor t' in the set of all binary
   trees having less or equal than n nodes, can be obtained as follows:

   2a) if t is a leaf then t' does not exist.
       otherwise t=(t_1,t_2)
   2b) if the successor t_2' of t_2 exists, then t' = (t_1,t_2')
       otherwise t_2 is maximal
   2c) if t_2 is a leaf then if the successor t_1' of t_1 exists, then
       t'=(t_1',Leaf)
   2d) if t_2 is not a leaf then we can borrow two nodes from t_2 to
       get the successor of t_1 in B: t_1'' = succ_gt(t_1).
       In that case t'=(t_1'',Leaf) and let us call t_2 the TAIL of the tree.

   Note that if succ_le is successful, the number of nodes in t' plus
   the number of nodes in the tail is equal n+2.


   3) succ_eq - successor in B(n) (with the same number of nodes)

   To get a successor of t with exactly n nodes we have to proceed as
   follows:

   3a) if t is a leaf then t' does not exist.
       otherwise t=(t_1,t_2)
   3b) if the successor t_2' of t_2 exists, then t' = (t_1,t_2')
       otherwise t_2 is maximal
   3c) if t_2 is a leaf then if the successor t_1'' = succ_le(t_1) exists
       then t'=(t_1'',t'') where t'' is the minimal tree with n''-2 nodes, where
       n'' is the number of nodes in the tail of the tree t_1.
   3d) if t_2 is not a leaf, then it is the tail itself, hence
       t'=(t_1',t_2'), where t_1' = succ_gt(t_1) and t_2' is a minimal tree
       with n_2-2 nodes, where n_2 is the number of nodes in t_2.



   The canonical implementation is written in Objective Caml for its
   facility in parsing, pretty printing and handling of variant data
   types.


   II. The  successor function --- implementation on bits in C
   ===========================================================

   It can be noticed that the above operations can be performed
   directly on the prefix representation of t, without building the
   tree explicitly.

   Given a non-zero number l, encoding a tree, it is enough to change
   the binary representation in the following way:

   a) find o and z such that l = [l' 0 1^o 0^z]
      it is always the case that o<z.
   b) if l' is 0 then the tree is maximal, z=o+1 and we have to return the
      minimal tree [(10)^o 0]
   c) otherwise the answer is
      [l' 1 0^{z-o+1} (10)^{o-1} 0]

   To understand why this is correct, first note that a maximal tree
   with n internal nodes and n+1 leaves (hence 2n+1 total nodes) has
   the code 1^n 0^n 0 and the minimal one (10)^n 0.

   Second, let us imagine two pointers denoting a substring of the
   prefix representation of the whole tree and let us establish the
   correspondence between moving the pointers and moving in the tree
   itself.

   Moving to the right subtree corresponds to advancing the left
   pointer over the left subtree while holding still the right
   pointer.

   Moving to the left subtree corresponds to advancing the left
   pointer by one position and moving back the right pointer
   over the right subtree.


   1) The function succ_gt which replaces the rightmost leaf with a
   node with two leafs, can be encoded on bit-strings as transforming
   [l 0] into [l 100].


   2) The function succ_le moves to the right subtree as far as
   possible (case 2b), and moves to the left subtree only if the right
   subtree is a leaf (case 2c). When the right subtree is a non-leaf
   maximal subtree (the tail), it is replaced by a leaf and succ_lt is
   called on the left-subtree (case 2d).

   On bit-strings the tail corresponds to the last substring of the
   form [1^n 0^n 0] and after the tail there can only be zeros. Since
   succ_le finally calls succ_gt, the whole operation on bit-strings is
   a transformation of [l 0 1^n 0^n 0 0^m] where n>0 into
   [l 100 0 0^m].


   3) The function succ_eq also moves to the right subtree as far as
   possible (case 3b). The two cases 3c and 3d correspond to finding
   the tail and replacing the rightmost subtree with a minimal tree
   with the number of nodes corresponding to the tail, decreased by
   two.  The tail is either found via succ_le (case 3c) or directly
   (case 3d).

   On bit-strings succ_eq is different from succ_le in replacing the
   last leaf with the representation of a minimal tree, so it
   transforms [l 0 1^n 0^n 0 0^m] where n>0 into
   [l 100 0 0^{m-1} (10)^{n-1} 0]. The difference between cases 3c and
   3d is m>0 in the first case and m=0 in the second case.


   Now, taking o=n and z=n+m+1, it can easily be seen that the bit
   operation described in the beginning is correct.

*/

//#define DEBUG(x) x
#define DEBUG(x)

#include<stdio.h>

typedef unsigned long num;

/* assuming [l = l'0 1^o 0^j] returns l'0,o,j. */
void getlast(num* l, int* o, int* z)
{
  *o = 0;
  *z = 0;
  if (*l!=0)
    {
      while (*l % 2 == 0)  /* counting zeros */
        {
          *l /= 2;
          (*z)++;
        };
      while (*l % 2 == 1)  /* counting ones */
        {
          *l /= 2;
          (*o)++;
        };
    };
}


/* transforms l into [l 0^{z-o-1} (10)^o 0 ]  */
void putbits(num* l, int o, int z)
{
  while (z>o+1)
    {
      *l *= 2;                /* l := l0 */
      z--;
    };

  /* z==o+1 */

  while (z>1)
    {
      *l = (*l * 2 + 1) * 2;  /* l := l10 */
      z--;
      o--;
    }

  /* z==1, o==0 */

  *l *= 2;                 /* l := l0 */

}



/* transforms [l = l'0 1..o..1 0..z..0]
   into [l'1 0..z-o+1..0 10..o-1..10 0 ] if l'<>0 or
   [10...o...10 0] otherwise */
num crunchbits(num l)
{
  int o,z;

  getlast(&l,&o,&z);

  DEBUG(fprintf(stderr,"get: l = %ld, o = %d, z = %d\n", l, o, z);)

  if (l==0)
    putbits(&l,o,z);
  else   /* l = l'0 */
    {
      l++;               /* l'1 */
      o--;
      z++;
      putbits(&l,o,z);
    }
  return l;
}


int main(void)
{
  num n;

  scanf("%ld",&n);

  DEBUG(fprintf(stderr,"%ld\n",n);)

  printf("%ld\n",crunchbits(n));

  return 0;
}

