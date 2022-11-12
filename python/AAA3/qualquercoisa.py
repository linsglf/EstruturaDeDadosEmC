'''importar a cotação do dólar do euro e do bitcoin'''

import requests

from tkinter import *



def pegar_cotacoes():
    requisicao = requests.get('https://economia.awesomeapi.com.br/all/USD-BRL,EUR-BRL,BTC-BRL')
    requisicao_dic = requisicao.json()

    cotacao_dolar = requisicao_dic['USD']['bid']
    cotacao_euro = requisicao_dic['EUR']['bid']
    cotacao_bitcoin = requisicao_dic['BTC']['bid']

    texto = f'''
    Cotação do Dólar: {cotacao_dolar}
    Cotação do Euro: {cotacao_euro}
    Cotação do Bitcoin: {cotacao_bitcoin}
    '''

    texto_cotacoes['text'] = texto

janela = Tk()

janela.title('Cotações')

janela.geometry('320x200')

texto_orientacao = Label(janela, text='Clique no botão para ver as cotações')
texto_orientacao.grid(column=1, row=0, pady= 10, sticky='nswe', columnspan=5)

botao = Button(janela, text='Cotações', command=pegar_cotacoes)
botao.grid(column=3, row=1, padx=130, pady=10, sticky='nswe', columnspan=1)

texto_cotacoes = Label(janela, text='')
texto_cotacoes.grid(column=3, row=2, pady=10, sticky='nswe', columnspan=1)

janela.mainloop()

    




