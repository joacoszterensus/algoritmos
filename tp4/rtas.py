from tp4 import page_graph


largest_component, num_components = page_graph.componenteMaxima()
print(f'Componente conexa más grande: {largest_component}')
print(f'Número de componentes conexas: {num_components}')

# 2
tiempoEstimado=page_graph.estimar_tiempo_camino_minimo(5)
print("El tiempo estimado en horas para caluclar el camino de todos con todos es ", tiempoEstimado)

# el orden del algoritmo de floyd warshal para calcular el camino minimo de todos con todos es o(v**3)

 # 3
triangulos=page_graph.poligonosTotal(3)
print(triangulos)
#extra 1
page_graph.graficoPoligonosEstimacion(max_k=6, muestra=10)


# 4
diametro_estimado = page_graph.estimar_diametro(num_muestras=10)
print(f"Diámetro estimado del grafo: {diametro_estimado}")


# 5
top_10_pagerank = page_graph.calcular_pagerank(100000,100)
print("Los 10 nodos más visitados:")
for nodo, rank in top_10_pagerank:
    print(f"Vértice {nodo}: {rank:.4f}")


# 6
print("circunferencia estimada: ", page_graph.circunferenciaEstimada(50))


# extra2
print("el coeficiente de clustering del grafo es: ",page_graph.calcular_coeficiente_clustering())   #0.35