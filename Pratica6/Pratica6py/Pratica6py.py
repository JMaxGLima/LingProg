from collections import deque

def print_stack(pilha):
    for elemento in pilha:
        print(elemento, end=" ")
    print()

def print_queue(fila):
    for elemento in fila:
        print(elemento, end=" ")
    print()

def main():
    # ====== LISTA (list) ======
    print("=== LISTA (list) ===")
    lista = [50, 40, 30, 20, 10]

    print("Lista:", end=" ")
    for elemento in lista:
        print(elemento, end=" ")
    print()

    del lista[2] 
    print("Lista após remover terceiro elemento:", end=" ")
    for elemento in lista:
        print(elemento, end=" ")
    print("\n")

    # ====== PILHA (usando deque) ======
    print("=== PILHA (deque) ===")
    pilha = deque()
    for elemento in lista:
        pilha.append(elemento)
        
    print("Pilha:")
    print_stack(pilha)
    print("Topo da pilha:", pilha[-1]) 

    pilha.pop()
    print("Pilha após pop:", end=" ")
    print_stack(pilha)
    print()

    # ====== FILA (usando deque) ======
    print("=== FILA (deque) ===")
    fila = deque()
    for elemento in lista:
        fila.append(elemento)
    print("Fila:")
    print_queue(fila)
    print("Frente da fila:", fila[0])

    fila.popleft()
    print("Fila após pop:", end=" ")
    print_queue(fila)

if __name__ == "__main__":
    main()