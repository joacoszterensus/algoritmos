//grafos
//work es una funcion random, que se le pasa como parametro, ej=elevar el num al 2

// void dfs(grafo,v,work):      0(v)
//     pila =pila():
//     pila.apilar(v):
//     while pila.vacia() == False:
//         v = pila.desapilar():
//        work(v):
//         for u in grafo.adyacentes(v):
//             pila.apilar(u)


// void bfs(grafo,v,work):      o(v)
//     cola =cola():
//     cola.encolar(v):
//     while cola.vacia() == False:
//         v = pila.desencolar():
//        work(v):
//         for u in grafo.adyacentes(v):
//             pila.encolar(u)


//                  1                   bfs     
//              2   |    3              [1] v=1
//          4     5 | 6       7         [2,3] v=3
//                                      [7,6,2] v=2
//                                      [5,4,7,6] v=6
//                                      [4,5,7] v=7
//                                      [5,4] v=4
//                                      [5] v=5
//
//las funciones anteriores funcionan para grafos sin ciclos
//si hay ciclos, se debe agregar un vector de visitados


// void dfs(grafo,v,work):              o(v + e) donde e es la cantidad de aristas y v la cantidad de vertices
//     visitados={} (set)
//     visitados.add(v)
//     pila =pila():
//     pila.apilar(v):
//     while pila.vacia() == False:
//         v = pila.desapilar():
//         work(v):
//         for u in grafo.adyacentes(v):
//             if u not in visitados:
//                 visitados.add(u)
//                 pila.apilar(u)
// para bfs es lo mismo solo que cambio la pila por una cola



/*
dfs_total(grafo):
    visitados={} (set)
    for v in grafo.vertices():
        if v not in visitados:
            dfs(grafo,v,visitados.add)


bool es_Completo(grafo):
    for v in grafo.vertices():
        if len(grafo.adyacentes(v)) != len(grafo.vertices())-1:
            return False
    return True

bool es_bipartito(grafo):
   colores={} (dict):
    for v in grafo.ve




CAMINOS MINIMOS
menor camino entre dos vertices
hay que tener encuenta los pesos de las aristas.(costo entre dos vertices)
a veces el camino mas corto no es el de menor costo

1) grafos sin ciclos(arbol)
    utilizo  dfs                         
    def bfs(origen, grafo):   me da la distancia desde un vertice a todos los demas     tiempo=o(v+e)
        pila=pila()                                                                     espacio=o(b*d) 
        padres={}
        disancias={}
        pila.apilar((null,origen,0))
        while pila.vacia() == False:
            o,v,d = pila.desapilar()
            if v not in padres or d<disancias[v]:
                padres[v]=o
                disancias[v]=d
                for u in grafo.adyacentes(v):
                    pila.apilar((v,u,d+1))
        return padres,disancias

seguimiento
a->b->e->f      padres={(a,null),(f,a),(b,a),(e,b)}
a->f            distancia={(a,0),(f,1),(b,1),(e,2)}

2)grafos con ciclos

    def bfs(origen,grafo)                  tiempo= o(v+e)
        cola=cola()                         memoria= o(b**d)
        distancias={}
        padres={}
        visitados={}
        cola.encolar((origen,0))
        padres[origen]=null
        visitados.add(origen)
        while cola.vacia() == False:
            v,d = cola.desencolar()
            distancias[v]=d
            for u in grafo.adyacentes(v):
                if u not in visitados:
                    visitados.add(u)
                    padres[u]=v
                    cola.encolar((u,d+1))
        return padres,distancias


  bfs_bidireccional(grafo,origen,destino)       tiempo=o(v+e) memoria=o(b**(d/2))
  se encuentran en el medio, por lo tanto utiliza menos memoria


  3)grafos con pesos con ciclos
    la distancia esta reemplazada por pesos
    utilizo una cola de prioridad
   
    def dijkstra(origen,grafo):                                 tiempo=o(v**2(log(v))+e)
        distancias={v:infinito for v in grafo.vertices()}       
        distancias[origen]=0
        padres={v:null for v in grafo.vertices()}
        visitados=set()
        cola=minHeap()
        cola.insert((origen,0))
        while not cola.vacia():
            v=cola.extract_Min()
            visitados.add(v)
            for n in grafo.adyacentes(v):
                if n not in visitados:
                    if distancias[v]+grafo.peso(v,n)<distancias[n]:
                        distancias[n]=distancias[v]+grafo.peso(v,n)
                        padres[n]=v
                        cola.insert((n,distancias[n]))

    a-1-b-1-f-1-g-1-e-4-c-2-a   
    distancias={a:0,b:1,f:2,g:3,e:4,c:2}
    padres={a:null,b:a,f:b,g:f,e:g,c:a}

4) grafos con ciclos y pesos positivos o negativos dijkstra funciona solo en algunos casos, se puede quedar atrapado en loops
    se utiliza bellman-ford
    
    def bellman_ford(origen,grafo)                  tiempo=o(v*e)-> pero caso es en un grafo completo o(v**3)
        distancias={v:infinito for v in grafo.vertices()}
        distancias[origen]=0
        for i in range(len(grafo.vertices())-1):
            for (u,v) in grafo.aristas():
                if distancias[u]+grafo.peso(u,v)<distancias[v]:
                    distancias[v]=distancias[u]+grafo.peso(u,v)
        for (u,v) in grafo.aristas():
            if distancias[u]+grafo.peso(u,v)<distancias[v]:
                return null
        return distancias



PROGRAMACION DINAMICA
    griddy(golosa)
    fuerza basica
    backtracking
    programacion dinamica


    fuerza bruta-resolver un problema probando todas las posibles soluciones
    backtracking- es como fuerza bruta pero se puede cortar la busqueda si se llega a un punto donde no se puede seguir(ej sudoku)
    griddy-bfs, dijkstra
            fibonacci-> se puede usar tabulacion o memoizacion que son distintos tipod de programacion dinamica.

    programacion dinamica
    monedas={5,10,20,25}
    cambio(n)-> nos devuelve la menor cantidad de monedas
    cambio(0)=0
    cambio(1)=infinito- no se puede
    cambio(2)=infinito- no se puede
    cambio(5)=1
    cambio(10)=1
    cambio(40)=min(cambio(25)+cambio(40-25)=cambio(20)+cambio(40-20)=....)
    cambio(n)=min(cambio(c)+cambio(n-c) for c in monedas if c<=n)
    def cambio(n,monedas):
        cambio={0:0}
       for i in range (n)
            cambio[i]=infinito if i not in monedas
        for i in range(1,n+1):
            cambio[i]=min(cambio[i-c]+1 for c in monedas if c<=i)
        return cambio[n]


5) caminos todos con todos con pesos negativos y positivos
a) for v in grafo.vertices():           tiempo=o(v**2*e)
        distancias=bellman_ford(v,grafo)    promedio o(v**3)    
        for u in grafo.vertices():           peor caso o(v**4)
            if distancias[u]<infinito:
                print(v,u,distancias[u])


b) def floyd_warshall(grafo)    prog dinamica      
    distancias [i][j]=infinito if i!=j or aristas    tiempo=o(v**3)
    distancias[i][j]=0 si i=j
    for k in range(grafo.vertices()):
        for i in range(grafo.vertices()):
            for j in range(grafo.vertices()):
                if distancias[i][j]>distancias[i][k]+distancias[k][j]:
                    distancias[i][j]=distancias[i][k]+distancias[k][j]
    return distancias



range minimum query
encontrar el minimo entre posiciones i y j

1)a la fuerza
           1     3   
array=[62,31,10,47,8,75,2,3,61]
costo de consulta(q)= o(n)
costo de preprocesamiento(p)=o(1)

2) precalculo todo con una matriz
i/j  0  1  2  3  4  5  6  7  

0    62 31 10 8  8  8  8  8
1    0  31 10 8  8  8  8  8
2    0  0  10 10 8  8  8  8
3    0  0  0  47  8  8 8  8
4    0  0  0  0   8  8 8  8
5    0  0  0  0   0  75 23 23
6    0  0  0  0   0  0  23 23
7    0  0  0  0   0  0  0  61
costo de consulta(q)= o(1)
costo de preprocesamiento(p)=o(n**2)


optimizacion con programacion dinamica
i/j  0  1  2  3  4  5  6  7 

0    62 31 10 8  8  8  8  8
1    0  31 10 8  8  8  8  8
2    0  0  10 10 8  8  8  8
3    0  0  0  47  8  8 8  8
4    0  0  0  0   8  8 8  8
5    0  0  0  0   0  75 23 23
6    0  0  0  0   0  0  23 23
7    0  0  0  0   0  0  0  61

q=o(1)
p=o(n**2)

3) solucion en bloques
dividimos en bloques de tamaño b
b=3
array=[28,71,49,36,51,11,19,3,99,64,12,55]
bloques=[[28,71,49],[36,51,11],[19,3,99],[64,12,55]]
minimos=[28,11,3,12]
p=o(n)
q=o(n/b  + b)

q optimo cuando b=raiz(n)-> o(raiz(n))

solucion 4) tabla dispersa
array=[62,31,10,47,8,75,2,3,61]

i/l  1  2  4  8  

0    62 31 10 8
1    31 10 8  -
2    10 10 8  -
3    47 8  8  -
4    8  8  8  -
5    75 23 -  -
6    23 23 -  -
7    61 -  -  -

p=o(nlog(n))
q=o(1)



              p     q
solucion 1    1     n
solucion 2    n**2  1      no sirve, sol 4 es mejor
solucion 3    n     raiz(n)
solucion 4    nlog(n)  1


solucion 5) hibrida
array=[28,71,49,36,51,11,19,3,99,64,12,55]
bloques=[[28,71,49],[36,51,11],[19,3,99],[64,12,55]]
superbloques=[28,11,3,12]-> aplico rmq 
tenemos[p1,q1] para el superbloque y [p2,q2] para el bloque
p: armo superbloque + lo que hago con el superbloque+ n/b * lo que hago con el bloque
q: q1(n/b)+q2(b)

solucion 3 (hibrida)
p1=o(1)     p2=o(1)
q1(x)=o(x)  q2(x)=o(x)

p= n + n/b +n/b* b = o(n)
q= n/b + b = o(n/b+b)-> o(raiz(n)+raiz(n))=o(raiz(n))


numeros catalanes
cn= 2n!/((n+1)!n!)
[1,2,3,4]<-->[10.20.30.40]   son isomorfos
Cantidad de bloques de tamaño b distintos= Cb

Método de los 4 rusos
Es un método para optimizar algoritmos en donde se usa una lookup table(diccionario)
en donde dos partes del problema tengan la misma solución. 

arboles cartesianos
es un arbol que cumpple con la propiedad de heap
su recorrido in order es igual al array original
[23,19,72,11,69,18]
            11
         19    18
     23    72 69      

se construye mediante el uso de una pila
algoitmo: para cada elemento leemos los elementos de iz a der
 1_desapilo hasta encontrar uno menor o hasta que la pila este vacia 
 2_ el padre del actual es el tope de la pila
 3-el hijo izquierdo del actual es el ultimo desapilado
 4_apilo el actual  

ej
[23,19,72,11,69,18]
pila=[]
arbol=[]

for i in range(len(array)):
    while pila and array[pila[-1]]<array[i]:
        pila.pop()
    if pila:
        arbol[pila[-1]].izq=i
    if pila:
        arbol[i].padre=pila[-1]
    pila.append(i)





*/




