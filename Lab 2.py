a1=float(input("Введіть першу сторону першого прямокутника"))
b2=float(input("Введіть другу сторону першого прямокутника"))
a2=float(input("Введіть першу сторону другого прямокутника"))
b2=float(input("Введіть другу сторону другого прямокутника"))
area1=a1*b1
area2=a2*b2
print("Площа першого прямокутника:",area1)
print("Площа другого прямокутника:", area2)
def hypotenuse(a, b):
    return math.sqrt(a**2 + b**2)

c1 = float(input("Введіть перший катет першого трикутника: "))
c2 = float(input("Введіть другий катет першого трикутника: "))
c3 = float(input("Введіть перший катет другого трикутника: "))
c4 = float(input("Введіть другий катет другого трикутника: "))

hyp1 = hypotenuse(c1, c2)
hyp2 = hypotenuse(c3, c4)

print("Гіпотенуза першого трикутника:", hyp1)
print("Гіпотенуза другого трикутника:", hyp2)

if hyp1 > hyp2:
    print("Гіпотенуза першого трикутника більша за гіпотенузу другого.")
elif hyp1 < hyp2:
    print("Гіпотенуза другого трикутника більша за гіпотенузу першого.")
else:
    print("Гіпотенузи обох трикутників рівні.")
def is_inside_circle(x, y, a, b, R):
    return (x - a)**2 + (y - b)**2 <= R**2

x = float(input("Введіть координату x точки: "))
y = float(input("Введіть координату y точки: "))
a = float(input("Введіть координату x центра кола: "))
b = float(input("Введіть координату y центра кола: "))
R = float(input("Введіть радіус кола: "))

if is_inside_circle(x, y, a, b, R):
    print("Точка лежить всередині кола.")
else:
    print("Точка не лежить всередині кола.")
X = float(input("Введіть довжину сторони X: "))
Y = float(input("Введіть довжину сторони Y: "))
Z = float(input("Введіть довжину сторони Z: "))
T = float(input("Введіть довжину сторони T: "))

area_quad = X * Y / 2  
print("Площа чотирикутника:", area_quad)
2n = int(input("Введіть число n: "))
divisors = list(map(int, input("Введіть числа, через пробіл, які діляють n: ").split()))

numbers = [num for num in range(1, n+1) if all(num % div == 0 for div in divisors)]

print("Натуральні числа, що діляться на всі введені числа:", numbers)