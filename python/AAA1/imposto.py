def somaImposto(taxaImposto, custo):
    custo = custo + (custo * taxaImposto / 100)
    return custo

taxaImposto = float(input("Digite a taxa de imposto: "))
custo = float(input("Digite o custo: "))

print("O custo com imposto é: ", somaImposto(taxaImposto, custo))
