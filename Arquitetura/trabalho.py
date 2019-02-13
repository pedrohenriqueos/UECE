#Nome: Pedro Henrique Oliveira Sousa
# Os exemplos estão no final do arquivo
import sys
class MIPS:
	def __init__(self):
		self.inicia()
	def inicia(self):
		self.registradores_nome = ['$zero', '$at', '$v0', '$v1', '$a0', '$a1', '$a2', '$a3', '$t0', '$t1', '$t2', '$t3', '$t4', '$t5', '$t6', '$t7', '$s0', '$s1', '$s2', '$s3', '$s4', '$s5', '$s6', '$s7', '$t8', '$t9', '$k0', '$k1', '$gp', '$sp', '$fp', '$ra']
		self.registradores_num = ['$0', '$1', '$2', '$3', '$4', '$5', '$6', '$7', '$8', '$9', '$10', '$11', '$12', '$13', '$14', '$15', '$16', '$17', '$18', '$19', '$20', '$21', '$22', '$23', '$24', '$25', '$26', '$27', '$28', '$29', '$30', '$31']
		self.registradores_code = ['00000', '00001', '00010', '00011', '00100', '00101', '00110', '00111', '01000', '01001', '01010',  '01011', '01100', '01101', '01110', '01111', '10000', '10001', '10010', '10011', '10100', '10101', '10110', '10111','11000', '11001', '11010','11011', '11100', '11101', '11110', '11111'] 
		self.instructions_r = ['add', 'addu', 'sub', 'subu', 'mult', 'multu', 'div', 'divu', 'mfhi', 'mflo', 'and', 'or', 'xor', 'nor', 'slt', 'sltu', 'sll', 'sllv', 'srl', 'srlv', 'sra', 'srav', 'jr', 'jalr', 'syscall']
		self.instructions_r_func = ['100000', '100001', '100010', '100011', '011000', '011001', '011010', '011011', '010010', '010010', '100100', '100101', '100110', '100111', '101010', '101011', '000000', '000100', '000010', '000110', '000011', '000111', '001000', '001001', '001100']
		self.instructions_i = ['addi', 'addiu', 'lw', 'lh', 'lhu', 'lb', 'lbu', 'sw', 'sh', 'sb', 'lui', 'ori', 'andi', 'xori', 'slti', 'sltiu', 'beq', 'bne']
		self.instructions_i_opcode = ['001000', '001001', '100011', '100001', '100101', '100000', '100100', '101011', '101001', '101000', '001111', '001101', '001100', '001110', '001010', '001011', '000100', '000101']
		self.instructions_j = ['j', 'jal']
		self.instructions_j_opcode = ['000010', '000011']
		self.directives = ['.text', '.data', '.long', '.byte', '.short', '.space', '.ascii']
		self.variaveis = []
		self.valores = []
		self.labels = []
		self.Code_label = []
def dec_bin(num):
	fim=""
	numbin = bin(num)
	for i in range(0,16-(len(numbin)-2)):
		fim+='0'
	for k in range(2,len(numbin)):								
		fim+=numbin[k]
	return fim
try:
	name = sys.argv[1]
	translate = sys.argv[2]
except IndexError:
	print("Erro de arquivo")
if name.endswith(".asm") and translate.endswith(".txt"):
	try:
		arq = open(name,'r')
		escrever = open(translate,'w')
		texto = arq.readlines()
		texto_final=[]
		contador=0
		Teste = MIPS()
		bloco=-1 # 0 -.text /1 -.data
		for linha in texto:
			contador = contador+1
			texto_escrever = []
			info = linha.split(" ")
			infofim=""
			for a in range(0,len(info[len(info)-1])-1):
				infofim+=info[len(info)-1][a]
			info[len(info)-1] = infofim
			if info[0]==Teste.directives[0] or info[0]==Teste.directives[1]:
				if info[0]==Teste.directives[0]:
					bloco=0
				else:
					bloco=1
				continue
			if bloco==0:
				if info[0][len(info[0])-1]==':':
					sub=""
					c= []
					for h in range(0,len(info[0])-1):
						sub+=info[0][h]
					Teste.labels.append(sub)
					Teste.Code_label.append(contador)
					for x in range(1,len(info)):
						c.append(info[x])
					info = c
				teste1=0
				for i in range(0,len(Teste.instructions_r)):
					if Teste.instructions_r[i]==info[0]:#verifica instruções r e codifica-as para bin
						teste1=1
						texto_escrever.append('000000')
						if i>=4 and i<=7:
							info2 = info[1].split(",")
							for j in range(0,len(Teste.registradores_nome)):
								if Teste.registradores_nome[j]==info2[0] or Teste.registradores_num[j]==info2[0]:
									texto_escrever.append(Teste.registradores_code[j])
									break
							for j in range(0,len(Teste.registradores_nome)):
								if Teste.registradores_nome[j]==info2[1] or Teste.registradores_num[j]==info2[1]:
									texto_escrever.append(Teste.registradores_code[j])
									break
						elif i>7 and i<=9:
							info2 = info[1].split(",")
							texto_escrever.append('00000')
							texto_escrever.append('00000')
							for j in range(0,len(Teste.registradores_nome)):
								if Teste.registradores_nome[j]==info2[0] or Teste.registradores_num[j]==info2[0]:
									texto_escrever.append(Teste.registradores_code[j])
									break
						elif i==16 or i==20:#sll
							info2 = info[1].split(",")
							texto_escrever.append('00000')
							for j in range(0,len(Teste.registradores_nome)):
								if Teste.registradores_nome[j]==info2[1] or Teste.registradores_num[j]==info2[1]:
									texto_escrever.append(Teste.registradores_code[j])
									break
							for j in range(0,len(Teste.registradores_nome)):
								if Teste.registradores_nome[j]==info2[0] or Teste.registradores_num[j]==info2[0]:
									texto_escrever.append(Teste.registradores_code[j])
									break
							for h in range(0,len(info2[2])):
								if not info2[2][h].isdigit():
									for x in range(0,len(Teste.variaveis)):
										if Teste.variaveis[x]==info2[2]:
											info2[2]=Teste.valores[x]
											break
									break
							num=int(info2[2])
							numbin=bin(num)
							fim=""
							for i in range(0,5-(len(numbin-2))):
								fim+='0'
							for i in range(2,len(numbin)):
								fim+=numbin[i]
						elif i==22 or i==23:
							testelabel=1
							for j in range(0,len(Teste.registradores_nome)):
								if Teste.registradores_nome[j]==info[1] or Teste.registradores_num[j]==info[1]:
									texto_escrever.append(Teste.registradores_code[j])
									testelabel=0
									break
							if testelabel==1:
								texto_escrever.append(info[1])
							texto_escrever.append('00000')
							texto_escrever.append('00000')
						elif i==24:
							texto_escrever.append('00000')
							texto_escrever.append('00000')
							texto_escrever.append('00000')
						else:
							info2 = info[1].split(",")
							for j in range(0,len(Teste.registradores_nome)):
								if Teste.registradores_nome[j]==info2[1] or Teste.registradores_num[j]==info2[1]:
									texto_escrever.append(Teste.registradores_code[j])
									break
							for j in range(0,len(Teste.registradores_nome)):
								if Teste.registradores_nome[j]==info2[2] or Teste.registradores_num[j]==info2[2]:
									texto_escrever.append(Teste.registradores_code[j])
									break
							for j in range(0,len(Teste.registradores_nome)):
								if Teste.registradores_nome[j]==info2[0] or Teste.registradores_num[j]==info2[0]:
									texto_escrever.append(Teste.registradores_code[j])
									break
						if i!=16 and i!=20:
							texto_escrever.append('00000')
						texto_escrever.append(Teste.instructions_r_func[i])	
				if teste1==0:
					info2 = info[1].split(",")
					for i in range(0,len(Teste.instructions_i)):#verifica instruções i e codifica-as para bin
						if Teste.instructions_i[i]==info[0]:
							texto_escrever.append(Teste.instructions_i_opcode[i])
							teste1=1
							if i>=2 and i<=9:							#2-9
								a=""
								registrador=""
								k=int(0)
								for i in range(k,len(info2[1])):
									if info2[1][i]=='(':
										k=i+1
										break
									else:
										a+=info2[1][i]
								num=int(a)
								for i in range(k,len(info2[1])):
									if info2[1][i]==')':
										break
									else:
										registrador+=info2[1][i]
								for j in range(0,len(Teste.registradores_nome)):
									if Teste.registradores_nome[j]==registrador or Teste.registradores_num[j]==registrador:
										texto_escrever.append(Teste.registradores_code[j])
										break
								for j in range(0,len(Teste.registradores_nome)):
									if Teste.registradores_nome[j]==info2[0] or Teste.registradores_num[j]==info2[0]:
										texto_escrever.append(Teste.registradores_code[j])
										break
							
								fima=dec_bin(num)
								texto_escrever.append(fima)
							elif i==10:							#lui
								fim=""
								texto_escrever.append('00000')
								for j in range(0,len(Teste.registradores_nome)):
									if Teste.registradores_nome[j]==info2[0] or Teste.registradores_num[j]==info2[0]:
										texto_escrever.append(Teste.registradores_code[j])
										break
								for h in range(0,len(info2[1])):
									if not info2[1][h].isdigit():
										for x in range(0,len(Teste.variaveis)):
											if Teste.variaveis[x]==info2[1]:
												info2[1]=Teste.valores[x]
												break
										break
								
								fima=dec_bin(int(info2[1]))
								texto_escrever.append(fima)
							elif i==16 or i==17:
								for j in range(0,len(Teste.registradores_nome)):
									if Teste.registradores_nome[j]==info2[0] or Teste.registradores_num[j]==info2[0]:
										texto_escrever.append(Teste.registradores_code[j])
										break
								for j in range(0,len(Teste.registradores_nome)):
									if Teste.registradores_nome[j]==info2[1] or Teste.registradores_num[j]==info2[1]:
										texto_escrever.append(Teste.registradores_code[j])
										break
								for h in range(0,len(info2[2])):
									if not info2[2][h].isdigit():
										for x in range(0,len(Teste.variaveis)):
											if Teste.variaveis[x]==info2[2]:
												info2[2]=Teste.valores[x]
												break
										break
								testeA=0
								for u in range(0,len(info2[2])):
									if not info2[2][u].isdigit():
										testeA=1
										texto_escrever.append(info2[2])
										break
								if testeA==0:
									fima=dec_bin(int(info2[2]))
									texto_escrever.append(fima)
							else:
								for j in range(0,len(Teste.registradores_nome)):
									if Teste.registradores_nome[j]==info2[1] or Teste.registradores_num[j]==info2[1]:
										texto_escrever.append(Teste.registradores_code[j])
										break
								for j in range(0,len(Teste.registradores_nome)):
									if Teste.registradores_nome[j]==info2[0] or Teste.registradores_num[j]==info2[0]:
										texto_escrever.append(Teste.registradores_code[j])
										break
								for h in range(0,len(info2[2])):
									if not info2[2][h].isdigit():
										for x in range(0,len(Teste.variaveis)):
											if Teste.variaveis[x]==info2[2]:
												info2[2]=Teste.valores[x]
												break
										break
								fima =dec_bin(int(info2[2]))
								texto_escrever.append(fima)
							break
				if teste1==0:
					for i in range(0,len(Teste.instructions_j)):#verifica instruções j e codifica-as para bin
						if Teste.instructions_j[i]==info[0]:
							teste1=1
							texto_escrever.append(Teste.instructions_j_opcode[i])
							for h in range(0,len(info[1])):
								if not info[1][h].isdigit():
									for x in range(0,len(Teste.variaveis)):
										if Teste.variaveis[x]==info[1]:
											info[1]=Teste.valores[x]
											break
									break
							testelabel=0
							for h in range(0,len(info[1])):
								if not info[1][h].isdigit():
									testelabel=1
									break
							if testelabel==0:
								num = int(info[1])
								fim=""
								numbin = bin(num)
								for i in range(0,26-(len(numbin)-2)):
									fim+='0'
								for k in range(2,len(numbin)):
									fim+=numbin[k]
								texto_escrever.append(fim)
							else:
								texto_escrever.append(info[1])
							break
						
			elif bloco==1:
				a=""
				for i in range(0,len(info[0])):
					if info[0][i]==':':
						break
					a+=info[0][i]
				Teste.variaveis.append(a)
				num=0
				if info[2][0]=='0' and info[2][1]=='x':
					f=0
					parc=0
					for k in range(len(info[2])-1,1,-1):
						if int(info[2][k])<=9:
							parc=(int(info[2][k])*(16**f))
						else:
							parc=(int(info[2][k])-int('a')+10)*(16**f)
						f=f+1
						num=num+parc
				elif info[2][0]=='0' and info[2][1]=='b':
					f=0
					parc=0
					for k in range(len(info[2])-1,1,-1):
						parc=(int(info[2][k])*(2**f))
						f=f+1
						num=num+parc
				else:
					num=info[2]
				Teste.valores.append(num)
			else:
				print("Configuração do texto incorreta")
				break
			saida=""
			for i in range(0,len(texto_escrever)):
				saida+=texto_escrever[i]
			if len(texto_escrever)>=1: 
				saida+='\n'
			texto_final.append(saida)
		for k in range(0,len(texto_final)):
			x=""
			for j in range(0,len(texto_final[k])-1):
				x+=texto_final[k][j]
			for w in range(0,len(x)):
				if x[w]!='0' and x[w]!='1':
					a=""
					for g in range(w,len(x)):
						if x[g]=='0' or x[g]=='1':
							break
						a+=x[g]
					for l in range(0,len(Teste.labels)):
						if Teste.labels[l]==a:
							numf = dec_bin(Teste.Code_label[l])
							novo_texto=""
							for i in range(0,6):
								novo_texto+=texto_final[k][i]
							for y in range(0,32-(len(numf)+6)):
								novo_texto+="0"
							novo_texto+=numf
							novo_texto+='\n'
							texto_final[k]=novo_texto
							break
					break
		escrever.writelines(texto_final)
		arq.close()
		escrever.close()
	except FileNotFoundError as e:
		print("Arquivo inexistente")
else:
	print("A terminação esta incorreta (.asm)- primeiro arquivo ,(.txt)- segundo arquivo")







#EXEMPLOS DE CÓDIGO EM ASSEMBLY

#EXEMPLO 1:
	#Assembly
.data
x: .long 0b20
.text
main: lui $t0,x
ori $t0,$t0,1
beq $s0,$s1,L
lw $a0,10($s2)
addi $v0,$a0,1
syscall
L: lui $t0,16
ori $t0,$t0,1
lh $a0,10($t0)
	#Resultado
00111100000010000000000000000100
00110101000010000000000000000001
00010000000000000000000000001010
10001110010001000000000000001010
00100000100000100000000000000001
00000000000000000000000000001100
00111100000010000000000000010000
00110101000010000000000000000001
10000101000001000000000000001010

#EXEMPLO 2:
	#Assembly
.text
main: subu $sp,$sp,$t0
sw $ra,20($sp)
sw $fp,16($sp)
addiu $fp,$sp,28
lui $a0,10
jal fact
lw $ra,20($sp)
lw $fp,16($sp)
addiu $sp,$sp,32
jr $ra
fact: subu $sp,$sp,$t0
sw $ra,20($sp)
sw $fp,16($sp)
addiu $fp,$sp,28
sw $a0,0($fp)
lw $v0,0($fp)
lui $v0,1
jr $ra
	#Resultado
00000011101010001110100000100011
10101111101111110000000000010100
10101111101111100000000000010000
00100111101111100000000000011100
00111100000001000000000000001010
00001100000000000000000000001100
10001111101111110000000000010100
10001111101111100000000000010000
00100111101111010000000000100000
00000011111000000000000000001000
00000011101010001110100000100011
10101111101111110000000000010100
10101111101111100000000000010000
00100111101111100000000000011100
10101111110001000000000000000000
10001111110000100000000000000000
00111100000000100000000000000001
00000011111000000000000000001000


#EXEMPLO 3:
	#Assembly	
.data
a: .long 120
x: .long 0x32
b: .long 0b10
.text
main: addi $s0,$0,a
lw $t0,4($sp)
sub $t0,$s0,$t0
addi $s0,$t0,x
addi $s0,$s0,b
sw $s0,4($sp)
syscall
	#Resultado
00100000000100000000000001111000
10001111101010000000000000000100
00000010000010000100000000100010
00100001000100000000000000110010
00100010000100000000000000000010
10101111101100000000000000000100
00000000000000000000000000001100
