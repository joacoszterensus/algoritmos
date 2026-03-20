#1
#a verdadero 
#b  verdadero
#c  falso
#d  

#2
# se hace num mod (cantidad de lugares) en este caso es mod 5
# por lo tanto 
# a->0
# b->1
# c->2
# d->3
# e->3
# f->3
#para si su lugar esta ocupado, voy a la siguiente posicion. esto se puede hacer solo 2 veces.
# en la parte del valor se inserta 0 si la posicion no esta ocupada y 1 si esta.

# 0   -  000
# 1   -  000
# 2   -  000    
# 3   -  000
# 4   -  000
# 5   -  000

#insert(a)
# 0   a  100
# 1   -  000
# 2   -  000    
# 3   -  000
# 4   -  000
# 5   -  000

#insert(d) -insert (e)-insert(b)
# 0   a  100
# 1   b  100
# 2   -  000    
# 3   d  110
# 4   e  000

#insert(f)
# 0   f  010
# 1   a  010
# 2   b  000    
# 3   d  111
# 4   e  000


#delete(a) insert(c)
# 0   f  000
# 1   b  100
# 2   c  100    
# 3   d  111
# 4   e  000


#3
# inicializa todas las distancias con infinito
# el padre de a es null
# la distancia de a es 0
# lo añade al dicc de distancias
# añade a los adyacentes al heap

# es el codigo de dijkstra


#4
# hago bfs para los dos vertices y listo.


#8
# uso las formulas
# p= falso positivo=0.0004
# n= cantidad de elem=2000000

#m optimo = -n*ln(p)/(ln(2)^2)
#k optimo = ln(2)*moptimo/n

#1301 bits


#10
#hago el promedio normal
# hago el promedio de los 7 mas chicos
#hago el promedio armonico


#5

# def angi(i):
#     if i <3 return...
#     if i==4 return...
#     if i==5 return...
#     else return angi(i-3)+angi(i-2)+angi(i-3)


# def angi(i)
#     if exists(i):
#         return getValue(i)
#     result=angi(i-3)+angi(i-2)+angi(i-3)
#     insertElement(i,result)
#     return result



import matplotlib.pyplot as plt
import numpy as np

# Definición de la función para graficar
def graficar_mercado_dinero():
    # Crear el gráfico
    fig, ax = plt.subplots()
    
    # Valores para el eje X (Cantidad de dinero)
    cantidad_dinero = np.linspace(0, 100, 200)
    
    # Curvas de demanda de dinero (MD)
    demanda_inicial = 100 - cantidad_dinero
    demanda_nueva = 80 - cantidad_dinero  # desplazada a la izquierda
    
    # Curvas de oferta de dinero (MS)
    oferta_inicial = 50 * np.ones_like(cantidad_dinero)
    oferta_nueva = 30 * np.ones_like(cantidad_dinero)  # desplazada a la izquierda
    
    # Graficar las curvas de demanda y oferta
    ax.plot(cantidad_dinero, demanda_inicial, label='Demanda de dinero (MD) inicial', color='blue')
    ax.plot(cantidad_dinero, demanda_nueva, label='Demanda de dinero (MD) nueva', linestyle='--', color='blue')
    ax.plot(cantidad_dinero, oferta_inicial, label='Oferta de dinero (MS) inicial', color='red')
    ax.plot(cantidad_dinero, oferta_nueva, label='Oferta de dinero (MS) nueva', linestyle='--', color='red')
    
    # Ajustes del gráfico
    ax.set_xlabel('Cantidad de dinero')
    ax.set_ylabel('Tasa de interés')
    ax.set_title('Mercado de dinero')
    ax.legend()
    ax.grid(True)
    
  
    
    
 
    
    plt.show()

# Llamada a la función para graficar
graficar_mercado_dinero()
