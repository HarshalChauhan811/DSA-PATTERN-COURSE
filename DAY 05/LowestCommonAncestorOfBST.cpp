class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {

        Node* a = p;   // Pointer a ko P node par rakh diya
        Node* b = q;   // Pointer b ko Q node par rakh diya

        // Jab tak dono pointers ek hi node par nahi pahuchte
        while (a != b) {

            // Agar a null ho gaya (top tak pahuch gaya),
            // to use q se dobara start kara do
            a = (a == nullptr) ? q : a->parent;

            // Agar b null ho gaya (top tak pahuch gaya),
            // to use p se dobara start kara do
            b = (b == nullptr) ? p : b->parent;
        }

        // Jis node par a aur b mil gaye wahi lowest common ancestor hai
        return a;
    }
};


/*
----------------------------- INTUITION -----------------------------

Ye technique Linked List cycle find karne wali two-pointer trick jaise chalti hai.

1. Dono pointers (a, b) apne-apne nodes (p, q) se start hote hain.
2. Dono **upar parent parent parent** jaate rahte hain.
3. Agar koi pointer top (nullptr) par pahuch jaye:
     usse doosre starting point se wapas start kara dete hain.

Isse kya hota hai?
- Dono pointers total same distance travel karte hain:
  distance(p → root) + distance(root → q)
  AND  
  distance(q → root) + distance(root → p)

Isliye **dono ek hi node par milte hi milte hain**, aur wahi LCA hoti hai.

--------------------------------------------------------------------

----------------------------- DRY RUN ------------------------------

Example Tree:
         A
       /   \
      B     C
     / \   / \
    D  E  F   G

Suppose:
p = D
q = E
LCA = B

Pointers:
a = D
b = E

Iteration 1:
a = D → parent = B
b = E → parent = B

a == b → B
Return B  ✔

---------------------------------------------------------

Example 2:
p = D
q = G
LCA = A

a path: D → B → A → nullptr → G → C → A  
b path: G → C → A → nullptr → D → B → A  

Dono last me A par milte hain ✔

--------------------------------------------------------------------

---------------------- TIME & SPACE COMPLEXITY ----------------------

Time Complexity:
- Har pointer maximum 2 baar tree ki height traverse karega.
- So total time = O(h)
(agar parent pointers hain to h = height of tree)

Space Complexity:
- Extra variables: a, b
- So space = O(1)

---------------------------------------------------------------------
*/
