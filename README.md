# EA876 2020.1
# Trabalho2

## Integrantes:
### nome: Enzo Hideki Iwata ra: 215394
### nome: Marcos Gabriel Diaz ra: 221525

## Comandos:

```make```: Compila todos os codigos. A funcao principal (main) filtra 100 vezes uma mesma imagem com o filtro Box Blur, para cada uma das três configurações de concorrência: linear (sem concorrência), muli-thread e multi-processo.

```make test```: Executa as filtragens e gera os gráficos, eles serão mostrados na tela e salvos em formato pdf.

```make clean```: Exclui os arquivos obejto (.o) e executáveis.

```make generate```: Roda uma iteração de cada configuração de recorrência e salva os resultados numa imagem.



#### Organização:
* conv: implementa a operacao de convolucao bidimensional em uma linha da imagem
* linear, process e thread: implementam o Box Blur de modo concorrente
* images: biblioteca de I/O de imagens (fornecida)
* cronometro: biblioteca para medição dos tempos (fornecida)
* gauss: implementa um filtro gaussiano de tamanho NxN arbitrario
* soel: implementa o operador de Sobel
* analise.py: recebe os tempos calculados e produz histogramas


OBS: Notamos que 100 iterações sobrescrevendo a imagem geravam muito swap de memória (não sabemos por que).
Assim, separamos os experimentos(faz todas as operações da convolução) da geração da imagem final.
