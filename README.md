# EA876 2020.1
# Trabalho2

## Integrantes:
### nome: Enzo Hideki Iwata ra: 215394
### nome: Marcos Gabriel Diaz ra: 221525

## Instrucoes
1. make clear para limpar os arquivos
2. make test para testar
3. make extra para bonus

## Comandos:

```make```: Compila todos os codigos. A funcao principal (main) filtra 100 vezes uma mesma imagem com o filtro Box Blur, para cada uma das três configurações de concorrência: linear (sem concorrência), muli-thread e multi-processo.

```make test```: Executa as filtragens e gera os gráficos. Eles serao salvos em formato pdf na pasta temp. As imagens sao salvas na pasta resultados.

```make clean```: Exclui os arquivos objeto (.o),  executáveis e imagens geradas.

```make extra```: Executa os filtros gaussiano e sobel (bonus) e salva as imagens no diretorio rsultados.

## OBS: histogramas fixos na pasta doc

#### Organização:
* conv: implementa a operacao de convolucao bidimensional em uma linha da imagem
* linear, process e thread: implementam o Box Blur de modo concorrente
* images: biblioteca de I/O de imagens (fornecida)
* cronometro: biblioteca para medição dos tempos (fornecida)
* gauss: produz um vetor de amostras da distribuição gaussiana 
* extra: contem os filtros extras
* analise.py: recebe os tempos calculados e produz histogramas

