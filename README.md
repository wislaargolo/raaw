# 🦖 Raaw 

Este projeto é um analisador léxico e sintático para a linguagem de programação **Raaw**, construído com as ferramentas **Flex** e **Bison**.

---

## 🔧 Requisitos

Você precisa do **Flex** e do **Bison** instalado no seu sistema.

### O que é o Flex?

**Flex (Fast Lexical Analyzer Generator)** é uma ferramenta que gera analisadores léxicos em C a partir de descrições formais. Ele interpreta regras definidas em um arquivo `.l` e gera um programa que reconhece padrões de entrada.

### O que é o Bison?

**Bison** é um gerador de analisadores sintáticos que, a partir de uma gramática definida em um arquivo `.y`, produz um parser em C. Ele é compatível com o Yacc (Yet Another Compiler Compiler) e é utilizado para interpretar a estrutura gramatical de uma linguagem de programação. 

### Como instalar o Flex no Linux

Caso ainda não tenha o Flex instalado, execute:

```bash
sudo apt install flex
```

---

### Como instalar o Bison no Linux

Caso ainda não tenha o Bison instalado, execute:

```bash
sudo apt install bison
```

## 🛠️ Compilação

Na pasta do projeto, gere o código fonte do analisador léxico a partir do arquivo `lex.l` com:

```bash
flex lex.l
```

Depois, gere o código fonte do analisador sintático a partir do arquivo `parser.y` com:

```bash
bison parser.y -o y.tab.c -d -v -g
```

Compile o código gerado com o GCC, criando o executável:

```bash
gcc lex.yy.c y.tab.c -o compiler
```

> O parâmetro `-lfl` é usado para linkar a biblioteca do Flex (`libfl`).

---

## ▶️ Execução

Para executar o analisador léxico em um dos arquivos de exemplo da pasta `exemplos/`, utilize o seguinte comando:

```bash
./compiler < exemplos/<nome_do_arquivo>.raaw
```

### Exemplo:

```bash
./compiler < exemplos/quickSort.raaw
```
---

## 📁 Estrutura do Projeto

```
.
├── exemplos/            # Arquivos de exemplo da linguagem Raaw
│   ├── exemplo1.raaw
│   └── exemplo2.raaw
├── compiler             # Arquivo executável gerado para compilação
├── lex.l                # Regras léxicas definidas em Flex
├── lex.yy.c             # Código C gerado automaticamente pelo Flex
├── parser.y             # Regras sintáticas definidas com o bison
├── y.output             # Saída gerada pelo bison com explicação do analisador sintático gerado
└── y.tab.c              # Código C gerado automaticamente pelo Bison
```

---

## ⚔️ Desafios Encontrados

### Conflitos
- Shift/Reduce:
  
O conflito shift/reduce identificado estava relacionado à regra `return_type`, usada para definir o tipo de retorno de funções da seguinte forma:

```ebnf
return_type : VOID
            | type
            ;
```

Quando aparecia um type seguido por um `ID`, o analisador não conseguia decidir se deveria consumir o `ID` - no caso de uma declaração de variável - ou reduzir imediatamente para return_type. Para resolver isso, a regra `return_type` foi removida e a declaração de função foi dividida em duas regras separadas: uma específica para funções com `VOID` e outra para funções com `type`.

- Reduce/Reduce:

Esse conflito tinha relação com a regra `cast` e ocorria quando existia um `ID` seguido por parênteses de fechamento `)`. Nessa situação, o analisador não conseguia decidir se deveria reduzir o `ID` como um `base` ou como um `type`. A solução proposta foi restringir o `cast` para que só seja permitido com tipos primitivos, eliminando a sobreposição entre `type` e `base` nesse contexto.

### Expressões na Sintaxe
Na nossa sintaxe, encontramos o problema de que expressões como `3.id` seriam corretas para a sintaxe, e ao tentar resolver esse problema tentando restringir o que pode vir antes do `'.'`, entretanto, ao criar regras para isso, obtivemos conflitos de shift/reduce. Logo, como não encontramos nenhuma maneira de resolver o problema sem gerar conflitos no analisador sintático, optamos por não resolver esses problemas na sintaxe para deixar o analisador sintático sem conflitos, e resolver os problemas posteriormente com semântica estática.
