# Timed Mini Shell

O mini shell deve ser capaz de ler um conjunto de comandos, pela entrada padrão, executar o comando e ao terminar a execução do comando ele deverá imprimir o tempo (em segundos) de execução e o código de retorno do programa.

## Milestones

- [ ] Ler a entrada padrão composta de duas strings (path do comando e argumento)
  - [ ] Testar lendo a entrada a partir de um arquivo
- [ ] Ler a entrada padrão enquanto for diferente de EOF
- [ ] Executar comando do path inserido (execl)
- [ ] Calcular quantos segundos o programa demorou a ser executado
- [ ] Capturar retorno do programa
  - [ ] Capturar o erro caso o path não exista
- [ ] Calcular o tempo total de execução do programa