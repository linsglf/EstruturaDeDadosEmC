'''Reproduzam e estudem o código de uma calculadora implementada em
Python e incluam funções trigonométricas no projeto.'''

from tkinter import *
from math import *

def soma():
    if entrada2.get() == '' or entrada1.get() == '':
        resultado['text'] = 'Preencha os campos'
    else:
        resultado['text'] = float(entrada1.get()) + float(entrada2.get())

def subtracao():
    if entrada2.get() == '' or entrada1.get() == '':
        resultado['text'] = 'Preencha os campos'
    else:
        resultado['text'] = float(entrada1.get()) - float(entrada2.get())

def multiplicacao():
    if entrada2.get() == '' or entrada1.get() == '':
        resultado['text'] = 'Preencha os campos'
    else:
        resultado['text'] = float(entrada1.get()) * float(entrada2.get())

def divisao():
    if entrada2.get() == '' or entrada1.get() == '':
        resultado['text'] = 'Preencha os campos'
    else:
        resultado['text'] = float(entrada1.get()) / float(entrada2.get())

def seno():
    if entrada1.get() != '':
        resultado['text'] = sin(float(entrada1.get()))
    else:
        resultado['text'] = sin(float(entrada2.get()))

def cosseno():
    if entrada1.get() != '':
        resultado['text'] = cos(float(entrada1.get()))
    else:
        resultado['text'] = cos(float(entrada2.get()))

def tangente():
    if entrada1.get() != '':
        resultado['text'] = tan(float(entrada1.get()))
    else:    
        resultado['text'] = tan(float(entrada2.get()))

def raiz():
    if entrada1.get() != '':
        resultado['text'] = sqrt(float(entrada1.get()))
    else:
        resultado['text'] = sqrt(float(entrada2.get()))

def limpar():
    resultado['text'] = ''

def sair():
    janela.quit()


janela = Tk()

janela.title('Calculadora')

janela.geometry('300x400')

texto_orientacao = Label(janela, text='Digite dois números')
texto_orientacao.grid(column=0, row=0, padx=100, pady=10, sticky='nswe', columnspan=4)

texto_numero1 = Label(janela, text='Número 1')
texto_numero1.grid(column=0, row=1, padx=10, pady=10, sticky='nswe', columnspan=2)

texto_numero2 = Label(janela, text='Número 2')
texto_numero2.grid(column=0, row=2, padx=10, pady=10, sticky='nswe', columnspan=2)

entrada1 = Entry(janela)
entrada1.grid(column=1, row=1, columnspan=4)

entrada2 = Entry(janela)
entrada2.grid(column=1, row=2, columnspan=4)

botao_soma = Button(janela, text='+', command=soma)
botao_soma.grid(column=1, row=3, padx=10, pady=10)

botao_subtracao = Button(janela, text='-', command=subtracao)
botao_subtracao.grid(column=2, row=3, padx=10, pady=10)

botao_multiplicacao = Button(janela, text='x', command=multiplicacao)
botao_multiplicacao.grid(column=1, row=4, padx=10, pady=10)

botao_divisao = Button(janela, text='/', command=divisao)
botao_divisao.grid(column=2, row=4, padx=10, pady=10)

botao_seno = Button(janela, text='sen', command=seno)
botao_seno.grid(column=1, row=5, padx=10, pady=10)

botao_cosseno = Button(janela, text='cos', command=cosseno)
botao_cosseno.grid(column=2, row=5, padx=10, pady=10)

botao_tangente = Button(janela, text='tan', command=tangente)
botao_tangente.grid(column=1, row=6, padx=10, pady=10)

botao_raiz = Button(janela, text='√', command=raiz)
botao_raiz.grid(column=2, row=6, padx=10, pady=10)

botao_limpar = Button(janela, text='Limpar', command=limpar)
botao_limpar.grid(column=2, row=7, padx=10, pady=10)

botao_sair = Button(janela, text='Sair', command=sair)
botao_sair.grid(column=1, row=7, padx=10, pady=10)

resultado = Label(janela, text='')
resultado.grid(column=0, row=8, padx=10, pady=10, sticky='nswe', columnspan=4)

janela.mainloop()


