// Dada una lista simplemente enlazada crear una función que elimine el “n-ésimo” nodo
// contando desde el último elemento. (por ejemplo si n =0 tiene que eliminar el último nodo, si
// n=1 tiene que eliminar el ante-último nodo, etc).
// Codificar la función bool remove_nth_last(struct Node* head) en O(n).
// Muchos puntos extras: Hacer la función recorriendo la lista una sola vez

// bool remove_nth_last(struct Node* head,int n){
//     node current=head
//     for (int i=0,i<n+1, i++ ){
//         current=current->next
//     }
//     node eliminar= head
//     while(current->next){
//         eliminar=eliminar->next
//         current=current->next
//     }
//     eliminar->next=eliminar->next->next

// }

// bfs_altura(v){
//     count=0
//     cola=cola()
//     cola.encolar(v)
//     while(!cola.vacia()){
//         u=cola.desencolar()
//         for vecino in u.adyacentes(){
//             pila.apilar(vecino)
//         }
//         count+=1
//     }
//     return count
// }
// find_best_root(g){
//     min=0
//     best=null
//     for vertice in g.vertices(){
//         altura=bfs_altura(vertice)
//         if altura>min{
//             min=altura
//             best=vertice
//         }
//     }
//     return vertice
// }

// bfs_d(v,d){
//     visitados=set()
//     cola=cola()
//     cola.encolar((v,0))
//     visitados.add(v)
//     while (!cola.vacia()){
//         u,dist=cola.desencolar()
//         if dist==d{
//             return u.adyacentes()
//         }
//         if u not in visitados{
//             visitados.append(u)
//             for vecino in u.adyacentes(){
//                 cola.encolar(vecino,dist+1)
//             }

//         }
//     }return NULL
// }
// ImprimirEquidistante(g,v1,v2,d){
//     equisdistantes1=bfs_d(v1,d)
//     equisdistantes2=bfs_d(v2,d)

//     equisdistantes=[]
//     for v in equidistantes1{
//         if equisdistantes2.contains(v){
//             equisdistantes.append(v)
//         }
//     }
//     return equisdistantes
// }

// treeToArrayInOrder(node,function){
//     if(!node){
//         return
//     }

//     treeToArrayInOrder(node->left,function)
//     function(node)
//     treeToArrayInOrder(node->right,function)

// }

// *SegundoSiguiente(struct Nodo *Actual){
//     a=[]
//     treeToArrayInOrder(actual,a.append)
//     return a[2]

// }