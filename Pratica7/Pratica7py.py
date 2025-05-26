"""
Program: Pratica7.py (Algoritmo de menor caminho)

Author: Joao Max Germano Lima

Date: 19/05/2025

Description: Programa em Python que implementa o algoritmo de Dijkstra para encontrar o menor caminho
entre dois nós ('s' e 't') em um grafo ponderado não-direcionado. O grafo é representado por uma
matriz de adjacência onde os pesos das arestas são dados e 'Inf' representa a ausência de conexão.
O programa calcula a distância mínima e o caminho correspondente entre os nós especificados.

License: CC BY
"""

import heapq  # Importa o módulo heapq para usar a fila de prioridade

# Define infinito como um valor numérico grande para representar ausência de conexão
Inf = 9999

# Matriz de adjacência representando o grafo ponderado
# Cada elemento matrix[u][v] representa o peso da aresta entre os nós u e v
matrix = [
    [0, 5, 1, 2, Inf, Inf, Inf, Inf, Inf],
    [5, 0, Inf, Inf, Inf, Inf, Inf, Inf, 3],
    [1, Inf, 0, Inf, 1, Inf, Inf, Inf, Inf],
    [2, Inf, Inf, 0, Inf, 1, Inf, Inf, Inf],
    [Inf, Inf, 1, Inf, 0, Inf, Inf, 1, Inf],
    [Inf, Inf, Inf, 1, Inf, 0, 1, Inf, Inf],
    [Inf, Inf, Inf, Inf, Inf, 1, 0, 3, 2],
    [Inf, 1, Inf, Inf, Inf, 1, Inf, 0, 3],
    [Inf, 3, Inf, Inf, Inf, Inf, 2, Inf, 0]
]

def dijkstra(matrix, s, t):
    """
    Implementação do algoritmo de Dijkstra para encontrar o menor caminho entre dois nós.
    
    Args:
        matrix: Matriz de adjacência representando o grafo
        s: Nó de origem
        t: Nó de destino
    
    Returns:
        tuple: (distância mínima, lista com o caminho)
    """
    
    n = len(matrix)  # Número de nós no grafo
    
    # Inicializa o vetor de distâncias com infinito
    dist = [Inf] * n
    dist[s] = 0  # A distância do nó de origem para ele mesmo é zero
    
    # Fila de prioridade (heap) para processar os nós
    heap = [(0, s)]
    
    # Vetor para marcar nós visitados
    visited = [False] * n
    
    # Vetor para armazenar o nó anterior (para reconstruir o caminho)
    previous = [-1] * n
    
    # Loop principal do algoritmo
    while heap:
        # Extrai o nó com menor distância atual
        current_dist, u = heapq.heappop(heap)
        
        # Se chegamos ao destino, podemos parar
        if u == t:
            break
        
        # Se já visitamos este nó, pulamos
        if visited[u]:
            continue
        
        # Marca o nó como visitado
        visited[u] = True
        
        # Explora todos os vizinhos do nó atual
        for v in range(n):
            # Verifica se existe conexão e se o nó não foi visitado
            if matrix[u][v] != Inf and not visited[v]:
                new_dist = current_dist + matrix[u][v]
                
                # Se encontramos um caminho mais curto, atualizamos
                if new_dist < dist[v]:
                    dist[v] = new_dist
                    previous[v] = u  # Atualiza o nó anterior
                    heapq.heappush(heap, (new_dist, v))  # Adiciona ao heap
    
    # Reconstrução do caminho do destino até a origem
    path = []
    current = t
    while current != -1:
        path.append(current)
        current = previous[current]
    path.reverse()  # Inverte para obter o caminho da origem ao destino
    
    return dist[t], path

# Exemplo de uso do algoritmo
if __name__ == "__main__":
    s = 0  # Nó de origem (0 é o primeiro nó)
    t = 8   # Nó de destino (8 é o último nó)
    
    # Chama a função dijkstra e obtém os resultados
    distance, path = dijkstra(matrix, s, t)
    
    # Exibe os resultados
    print(f"Menor distância entre {s} e {t}: {distance}")
    print(f"Caminho: {path}")