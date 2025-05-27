# 🦖 Raaw Lexer

Este projeto é um analisador léxico para a linguagem de programação **Raaw**, construído com a ferramenta **Flex**.

---

## 🔧 Requisitos

Você precisa do **Flex** instalado no seu sistema.

### O que é o Flex?

**Flex (Fast Lexical Analyzer Generator)** é uma ferramenta que gera analisadores léxicos em C a partir de descrições formais. Ele interpreta regras definidas em um arquivo `.l` e gera um programa que reconhece padrões de entrada.

### Como instalar o Flex no Linux

Caso ainda não tenha o Flex instalado, execute:

```bash
sudo apt install flex
```

---

## 🛠️ Compilação

Na pasta do projeto, gere o código fonte a partir do arquivo `lex.l` com:

```bash
flex lex.l
```

Compile o código gerado com o GCC, criando o executável:

```bash
gcc lex.yy.c -o lex -lfl
```

> O parâmetro `-lfl` é usado para linkar a biblioteca do Flex (`libfl`).

---

## ▶️ Execução

Para executar o analisador léxico em um dos arquivos de exemplo da pasta `exemplos/`, utilize o seguinte comando:

```bash
./lex < exemplos/<nome_do_arquivo>.raaw > out.txt
```

### Exemplo:

```bash
./lex < exemplos/quickSort.raaw > out.txt
```

O resultado da análise será salvo no arquivo `out.txt`.

---

## 📁 Estrutura do Projeto

```
.
├── exemplos/            # Arquivos de exemplo da linguagem Raaw
│   ├── exemplo1.raaw
│   └── exemplo2.raaw
├── lex                  # Executável compilado com GCC
├── lex.l                # Regras léxicas definidas em Flex
├── lex.yy.c             # Código C gerado automaticamente pelo Flex
└── out.txt              # Arquivo de saída da análise léxica
```
