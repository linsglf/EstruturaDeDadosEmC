'''Utilizando a biblioteca gráfica Tkinter, o aluno deve construir uma
interface que simule uma tela de login de usuário contendo o campo de login,
senha e um botão de autenticação.'''

from tkinter import *

def login():
    if usuario.get() == 'admin' and senha.get() == 'admin':
        texto['text'] = 'Login efetuado com sucesso !'
    else:
        texto['text'] = 'Usuário ou senha inválidos'

janela = Tk()

janela.title('Login')

janela.geometry('220x200')

texto_orientacao = Label(janela, text='Digite o usuário e a senha')
texto_orientacao.grid(column=0, row=0,padx=40, pady=10, sticky='nswe', columnspan=4)

texto_usuario = Label(janela, text='Usuário')
texto_usuario.grid(column=0, row=1, padx=10, pady=10, sticky='nswe', columnspan=1)

texto_senha = Label(janela, text='Senha')
texto_senha.grid(column=0, row=2,padx= 10, pady=10, sticky='nswe', columnspan=1)

usuario = Entry(janela)
usuario.grid(column=1, row=1, columnspan=2)

senha = Entry(janela)
senha.grid(column=1, row=2, columnspan=2)

botao = Button(janela, text='Login', command=login)
botao.grid(column=0, row=3,padx= 20, sticky='nswe', columnspan=4)

texto = Label(janela, text='')
texto.grid(column=0, row=4, padx=10, pady=10, sticky='nswe', columnspan=4)

janela.mainloop()

