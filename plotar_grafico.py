import matplotlib.pyplot as plt
import csv
import os

def gerar_grafico(nome_ficheiro_csv, nome_imagem_saida, titulo):
    if not os.path.exists(nome_ficheiro_csv):
        print(f"Aviso: O ficheiro {nome_ficheiro_csv} não foi encontrado.")
        return

    tamanhos, insertion, selection, bubble, quick, merge = [], [], [], [], [], []

    with open(nome_ficheiro_csv, 'r', encoding='utf-8') as file:
        reader = csv.reader(file)
        next(reader) 
        
        for row in reader:
            if not row: continue 
            tamanhos.append(int(row[0]))
            insertion.append(int(row[1]))
            selection.append(int(row[2]))
            bubble.append(int(row[3]))
            quick.append(int(row[4]))
            merge.append(int(row[5]))

    plt.figure(figsize=(10, 6))
    plt.plot(tamanhos, insertion, label='Insertion Sort', marker='o', linestyle='-')
    plt.plot(tamanhos, selection, label='Selection Sort', marker='s', linestyle='-')
    plt.plot(tamanhos, bubble, label='Bubble Sort', marker='^', linestyle='-')
    plt.plot(tamanhos, quick, label='Quick Sort', marker='x', linestyle='--')
    plt.plot(tamanhos, merge, label='Merge Sort', marker='d', linestyle='--')

    plt.xlabel('Tamanho do Array (N)')
    plt.ylabel('Tempo Médio de Execução (Nanossegundos)')
    plt.title(titulo)
    plt.legend()
    plt.grid(True, linestyle=':', alpha=0.7)
    
    plt.savefig(nome_imagem_saida, dpi=300, bbox_inches='tight')
    print(f"Sucesso: Gráfico guardado como '{nome_imagem_saida}'.")
    plt.close()

# Executa a função para ler os ficheiros do melhor e do pior caso
gerar_grafico('resultados_finais_piorcaso.csv', 'grafico_pior_caso.png', 'Comparação de Algoritmos - Pior Caso')
gerar_grafico('resultados_finais_melhorcaso.csv', 'grafico_melhor_caso.png', 'Comparação de Algoritmos - Melhor Caso')