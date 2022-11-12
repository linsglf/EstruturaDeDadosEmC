def area_trapezio(base_maior, base_menor, altura):
    area = (base_maior + base_menor) * altura / 2
    return area

base_maior = float(input("Digite a base maior: "))
base_menor = float(input("Digite a base menor: "))
altura = float(input("Digite a altura: "))

print("A área do trapézio é: ", area_trapezio(base_maior, base_menor, altura))

