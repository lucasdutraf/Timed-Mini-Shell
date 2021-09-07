# Timed Mini Shell

O mini shell deve ser capaz de ler um conjunto de comandos, pela entrada padrão, executar o comando e ao terminar a execução do comando ele deverá imprimir o tempo (em segundos) de execução e o código de retorno do programa.

## Milestones

- [x] Ler a entrada padrão composta de duas strings (path do comando e argumento)
  - [x] Testar lendo a entrada a partir de um arquivo
- [x] Ler a entrada padrão enquanto for diferente de EOF
- [x] Criar um processo filho para executar o comando
  - [x] Executar comando do path inserido (execl)
- [ ] Calcular quantos segundos o programa demorou a ser executado
- [ ] Capturar retorno do programa
  - [x] Capturar o erro caso o path não exista
- [x] Calcular o tempo total de execução do programa
## Executando o projeto

- Compilando o projeto:
```bash
    make comp
```

- Executando o projeto:
```bash
    make exec
```

- Compilando e executando o projeto
```bash
    make run
```

- Executando com inputs de arquivo e redirecionando a saída para um arquivo
```bash
    make run-file
```