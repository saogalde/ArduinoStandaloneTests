arch = open("/Users/saogalde/EmbeddedCosas/NTC_3905_10k.c", "w")
fun = lambda x: 1.2448950462E-19*x**6 - 1.1592210345E-16*x**5 - 6.4359094861E-12*x**4 + 3.5457906054E-08*x**3 - 7.7785187603E-05*x**2 + 1.0065860789E-01*x - 5.1213085902E+01
l = []
arch.write("const float NTC_temperatures[] = { ")
for i in range(4096):
	
	if i%3==0:
		salto = ",\n"
	else:
		salto = ", "
	l.append(str(fun(i))+salto)

arch.writelines(l)	
arch.write("};")

