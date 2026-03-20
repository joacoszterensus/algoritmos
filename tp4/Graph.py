import random
import time
import matplotlib.pyplot as plt
from collections import deque
from tqdm import tqdm



class Graph:
    def __init__(self):
        self.vertices = {}

    def add_vertex(self, vertex):
        if vertex not in self.vertices:
            self.vertices[vertex] = []

    def add_edge(self, vertex1, vertex2):
        if vertex1 in self.vertices and vertex2 in self.vertices:
            self.vertices[vertex1].append(vertex2)

    def vertex_exists(self, vertex):
        return vertex in self.vertices
    
    def dfs(self, vertex, visited):
        stack = [vertex]
        componentes = []
        while stack:
            v = stack.pop()
            if v not in visited:
                visited.add(v)
                componentes.append(v)
                for vecino in self.vertices[v]:
                    if vecino not in visited:
                        stack.append(vecino)
        return componentes

    def componentesConexas(self):
        visitados = set()
        componentes = []
        for vertex in self.vertices:
            if vertex not in visitados:
                componente = self.dfs(vertex, visitados)
                componentes.append(componente)
        return componentes

    def componenteMaxima(self):
        componente = self.componentesConexas()
        componenteMaxima = max(componente, key=len)
        return len(componenteMaxima), len(componente)
    

    def bfsCaminosMInimos(self, inicio, fin):
        if inicio == fin:
            return 0

        visitados = set()
        queue = [(inicio, 0)]

        while queue:
            nodo_actual, distancia = queue.pop(0)
            if nodo_actual in visitados:
                continue
            visitados.add(nodo_actual)

            for vecino in self.vertices.get(nodo_actual, []):
                if vecino == fin:
                    return distancia + 1
                if vecino not in visitados:
                    queue.append((vecino, distancia + 1))

        return float('inf')  

    def estimar_tiempo_camino_minimo(self, num_muestras):
        nodos = list(self.vertices.keys())
        tiempos = []

        for _ in range(num_muestras):
            inicio, fin = random.sample(nodos, 2)
            start_time = time.time()
            self.bfsCaminosMInimos(inicio, fin)
            end_time = time.time()
            tiempos.append(end_time - start_time)

        tiempo_promedio = sum(tiempos) / num_muestras
        tiempo_estimado = tiempo_promedio * len(nodos)
        horas=tiempo_estimado//3600
        return int(horas)
    
    
    def dfsPoligonos(self, node, start, k, visited):
        if k == 0:
            return 1 if node == start else 0
        count = 0
        visited.add(node)
        for neighbor in self.vertices[node]:
            if neighbor not in visited or (neighbor == start and k == 1):
                count += self.dfsPoligonos(neighbor, start, k - 1, visited)
        visited.remove(node)
        return count

    def poligonosTotal(self, k):
        total_count = 0
        for vertex in self.vertices:
            total_count += self.dfsPoligonos(vertex, vertex, k, set())        
        return total_count 
    

    def muestraPoligonos(self, k, sample_size):
        total_count = 0
        sample_nodes = random.sample(list(self.vertices.keys()), sample_size)
        for vertex in sample_nodes:
            total_count += self.dfsPoligonos(vertex, vertex, k, set())
        estimated_total = (total_count ) * (len(self.vertices) / sample_size)
        return estimated_total

    def graficoPoligonosEstimacion(self, max_k, muestra):
        ks = range(3, max_k + 1)
        counts = []
        for k in ks:
            count = self.muestraPoligonos(k,  muestra)
            counts.append(count)
            

        plt.plot(ks, counts, marker='o')
        plt.xlabel('numero de lados')
        plt.ylabel('estimacion de poligonos')
        plt.title('Estimacion de poligonos en funcion de los lados')
        plt.show()

  

    
    def coeficiente_clustering_nodo(self, nodo):
        vecinos = self.vertices[nodo]
        if len(vecinos) < 2:
            return 0.0

        enlaces_entre_vecinos = 0
        for i in range(len(vecinos)):
            for j in range(i + 1, len(vecinos)):
                if vecinos[j] in self.vertices[vecinos[i]]:
                    enlaces_entre_vecinos += 1

        max_enlaces_posibles = len(vecinos) * (len(vecinos) - 1) / 2
        return enlaces_entre_vecinos / max_enlaces_posibles

    def calcular_coeficiente_clustering(self):
        coeficientes_nodos = []
        for nodo in self.vertices:
            coeficiente = self.coeficiente_clustering_nodo(nodo)
            coeficientes_nodos.append(coeficiente)

        coeficiente_clustering_grafo = sum(coeficientes_nodos) / len(self.vertices)
        return coeficiente_clustering_grafo
    
    
    
    def bfsDIametro(self, inicio):
        distancias = {inicio: 0}
        queue = [(inicio, 0)]

        while queue:
            nodo_actual, distancia = queue.pop(0)
            for vecino in self.vertices.get(nodo_actual, []):
                if vecino not in distancias:
                    distancias[vecino] = distancia + 1
                    queue.append((vecino, distancia + 1))

        return distancias

    def estimar_diametro(self, num_muestras):
        nodos = list(self.vertices.keys())

        diametro_estimado = 0
        for i in range(num_muestras):
            inicio = random.choice(nodos)
            distancias = self.bfsDIametro(inicio)
            max_distancia = max(distancias.values())
            if max_distancia > diametro_estimado:
                diametro_estimado = max_distancia

        return diametro_estimado
    
    def random_walk(self, start_vertex, walk_length):
        current_vertex = start_vertex
        walk = [current_vertex]

        for i in range(walk_length):
            if self.vertices[current_vertex]:
                current_vertex = random.choice(self.vertices[current_vertex])
                walk.append(current_vertex)
            else:
                break 

        return walk

    def calcular_pagerank(self, num_walks, walk_length):
        visitas = {v: 0 for v in self.vertices}

        nodos = list(self.vertices.keys())
        for i in range(num_walks):
            start_vertex = random.choice(nodos)
            walk = self.random_walk(start_vertex, walk_length)
            for vertex in walk:
                visitas[vertex] += 1

        total_visitas = sum(visitas.values())
        pagerank = {v: visitas[v] / total_visitas for v in self.vertices}

        top_10 = sorted(pagerank.items(), key=lambda x: x[1], reverse=True)[:10]
        
        return top_10
    




    def circunferenciaEstimada(self, k):
        vertices = random.sample(list(self.vertices.keys()), k)
        maximo_ciclo = 0
        
        for start in tqdm(vertices, total=k):
            visitado = set()
            distancia = {start: 0}
            cola = deque([start])
            
            while cola:
                nodo = cola.pop()
                
                for vecino in self.vertices[nodo]:
                    if vecino == start and distancia[nodo] > 0:
                        maximo_ciclo = max(maximo_ciclo, distancia[nodo] + 1)
                    
                    if vecino not in visitado:
                        visitado.add(vecino)
                        distancia[vecino] = distancia[nodo] + 1
                        cola.append(vecino)
        
        return maximo_ciclo