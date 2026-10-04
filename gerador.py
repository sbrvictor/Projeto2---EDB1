import os

# Cria subpastas para não misturar os cenários
os.makedirs("test_data/pior_caso", exist_ok=True)
os.makedirs("test_data/melhor_caso", exist_ok=True)

# Gera tamanhos de 25.000 até 500.000. 
# Usamos saltos de 25.000 para não criar ficheiros a mais, mas manter um gráfico detalhado.
tamanhos = list(range(25000, 500001, 25000))

def gerar_arquivos(num_exercicio, tamanhos):
    for val in tamanhos:
        nome_base = f"p{num_exercicio}v{val}.txt"
        
        # Pior Caso: Ordem Decrescente
        with open(f"test_data/pior_caso/{nome_base}", 'w') as f:
            f.write(" ".join([str(i) for i in range(val, 0, -1)]))
            
        # Melhor Caso: Ordem Crescente (já ordenado)
        with open(f"test_data/melhor_caso/{nome_base}", 'w') as f:
            f.write(" ".join([str(i) for i in range(1, val + 1)]))
            
        print(f"Ficheiros para o tamanho {val} gerados com sucesso!")

# Executa para o nosso prefixo p1
gerar_arquivos(1, tamanhos)