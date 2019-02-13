package rpgArquivo;

import java.io.*;
import java.util.*;

public class Aventureiro extends Personagem{
	private File memoria;
	private String nameArquivo;
	private ArrayList<Integer> x=new ArrayList<Integer>();
	private ArrayList<Integer> y=new ArrayList<Integer>();
	private int control=0;
	public Aventureiro(String arquivo){
		super(TipoElemento.Aventureiro);
		File a = new File(arquivo);
		a.delete();
		File b = new File(arquivo);
		this.setMemoria(b);
		this.setNameArquivo(arquivo);
	}
	public void setControl(int control){
		this.control=control;
	}
	public String getNameArquivo(){
		return this.nameArquivo;
	}
	public void setNameArquivo(String nome){
		this.nameArquivo=nome;
	}
	public File getMemoria() {
		return memoria;
	}

	public void setMemoria(File memoria) {
		this.memoria = memoria;
	}

	public boolean encontrouTesouro(Camara a){
		return ((this.getX()==a.getDimensao()-3 && this.getY()==a.getDimensao()-1 &&((a.getCenario()[this.getX()+1][this.getY()]==TipoElemento.EspacoVazio)||(a.getCenario()[this.getX()+1][this.getY()]==TipoElemento.Espaco)))||(this.getX()==a.getDimensao()-1 && this.getY()==a.getDimensao()-3 &&(a.getCenario()[this.getX()][this.getY()+1]==TipoElemento.EspacoVazio||a.getCenario()[this.getX()][this.getY()+1]==TipoElemento.Espaco))
				||(this.getX()==a.getDimensao()-2 && this.getY()==a.getDimensao()-1)||(this.getX()==a.getDimensao()-1 && this.getY()==a.getDimensao()-2));
	}
	public boolean encontrouMensagem(Camara a){
		return ((this.getX()==a.getDimensao()-3 && this.getY()==a.getDimensao()-1 &&((a.getCenario()[this.getX()+1][this.getY()]==TipoElemento.EspacoVazio)||(a.getCenario()[this.getX()+1][this.getY()]==TipoElemento.Espaco)))||(this.getX()==a.getDimensao()-1 && this.getY()==a.getDimensao()-3 &&(a.getCenario()[this.getX()][this.getY()+1]==TipoElemento.EspacoVazio||a.getCenario()[this.getX()][this.getY()+1]==TipoElemento.Espaco))
				||(this.getX()==a.getDimensao()-2 && this.getY()==a.getDimensao()-1)||(this.getX()==a.getDimensao()-1 && this.getY()==a.getDimensao()-2));
	}
	public void mover(int k,Camara c) throws AcaoInvalidaException{
		Random a=new Random();
		System.out.println();
		for(int j=0;j<c.getDimensao();j++)
			System.out.print("------");
		System.out.println();
		if(this.getTipo()==TipoElemento.Aventureiro)
			System.out.print("Aventureiro ");
		else
			System.out.print("JoaoD ");
		try{
			if(control!=0){
			try{
				FileReader fr = new FileReader(this.getNameArquivo());
				BufferedReader br = new BufferedReader(fr);
				String linha = br.readLine();
				while(linha !=null){
					String[] dados = linha.split(" ");
					if(dados[2]=="Obstaculo"){
						x.add(Integer.parseInt(dados[0]));
						y.add(Integer.parseInt(dados[1]));
					}
					linha = br.readLine();
				}
				br.close();
				fr.close();
			}catch(FileNotFoundException e3){
				System.out.println(" Arquivo não encontrado");
				e3.printStackTrace();
			}catch(IOException e3){
				System.out.println(" Erro de leitura");
				e3.printStackTrace();
			}
			}
			int test=0,n=0,m=0;
			boolean t=false;
			for(int i=0;i<x.size();i++){
				if(this.getX()+1==x.get(i) && this.getY()==y.get(i)){
					n=x.get(i);
					m=y.get(i);
					t=true;
					break;
				}
				else if(this.getX()-1==x.get(i) && this.getY()==y.get(i)){
					n=x.get(i);
					m=y.get(i);
					t=true;
					break;
				}
				else if(this.getX()==x.get(i) && this.getY()+1==y.get(i)){
					n=x.get(i);
					m=y.get(i);
					t=true;
					break;
				}
				else if(this.getX()==x.get(i) && this.getY()-1==y.get(i)){
					n=x.get(i);
					m=y.get(i);
					t=true;
					break;
				}
			}
			int h=0,g=0;
			if(t){
				if(this.getX()+1==c.getJoao().getX() && this.getY()==c.getJoao().getY()){
					h= this.getX()-n;
					g= this.getY()-m;
					test++;
				}
				else if(this.getX()-1==c.getJoao().getX() && this.getY()==c.getJoao().getY()){
					h= this.getX()-n;
					g= this.getY()-m;
					test++;
				}
				else if(this.getX()==c.getJoao().getX() && this.getY()+1==c.getJoao().getY()){
					h= this.getX()-n;
					g= this.getY()-m;
					test++;
				}
				else if(this.getX()==c.getJoao().getX() && this.getY()-1==c.getJoao().getY()){
					h= this.getX()-n;
					g= this.getY()-m;
					test++;
				}else
					t=false;
				if(test==1){
					if(h==1)
						k=3;
					else if(h==-1)
						k=0;
					else if(g==1)
						k=1;
					else if(g==-1)
						k=2;
				}
			}
			if(test==0){
			for(int i=0;i<x.size();i++){
				if(this.getX()+1==x.get(i) && this.getY()==y.get(i) && Movimento.down.getValor()==k){
					while(Movimento.down.getValor()!=k){
						a = new Random();
						k=a.nextInt(4);
						i=0;
					}
				}
				else if(this.getX()-1==x.get(i) && this.getY()==y.get(i) && Movimento.up.getValor()==k){
					while(Movimento.up.getValor()!=k){
						a = new Random();
						k=a.nextInt(4);
						i=0;
					}
				}
				else if(this.getX()==x.get(i) && this.getY()+1==y.get(i) && Movimento.right.getValor()==k){
					while(Movimento.right.getValor()!=k){
						a = new Random();
						k=a.nextInt(4);
						i=0;
					}
				}
				else if(this.getX()==x.get(i) && this.getY()-1==y.get(i) && Movimento.left.getValor()==k){
					while(Movimento.left.getValor()!=k){
						a = new Random();
						k=a.nextInt(4);
						i=0;
					}
				}
			}
			}
			if(Movimento.down.getValor()==k){
				this.setX(this.getX()+1);
				System.out.println("Move down");
				if(this.getX()>=c.getDimensao()){
					this.setX(this.getX()-1);
					c.visualizarCenario();
					throw new AcaoInvalidaException(Movimento.down);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.Obstaculo){//escrever
					this.EscreverArquivo(c);
					for(Obstaculo o: c.getObstaculos()){
						if(o.getX()==this.getX() && o.getY()==this.getY()){
							if(o.getResistencia()==EResistencia.Fragil)
								c.getCenario()[this.getX()][this.getY()]=TipoElemento.EspacoVazio;
							break;
						}
					}
					this.setX(this.getX()-1);
					c.visualizarCenario();
					if(this.getTipo()==TipoElemento.Aventureiro && c.getTipo()!=TipoCamara.camaraErrada){
						int ponto=((k==0)?3:((k==2)?1:((k==3)?0:2)));
						c.getJoao().mover(ponto,c);
						if(c.getJoao().verificaAventureiro(c))
							c.getJoao().setAcho(true);
						c.getJoao().mover(ponto,c);
						if(c.getJoao().verificaAventureiro(c))
							c.getJoao().setAcho(true);
						System.out.println();
						System.out.print("Aventureiro: ");
					}
					if(this.getTipo()==TipoElemento.JoaoDorminhoco){
						System.out.println();
						System.out.print("João Dorminhoco: ");
					}
						throw new AcaoInvalidaException();
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.JoaoDorminhoco){
					this.setX(this.getX()-1);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.Aventureiro){
					if(this.getTipo()==TipoElemento.JoaoDorminhoco)
						c.getJoao().setAcho(true);
					this.setX(this.getX()-1);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.EspacoVazio||c.getCenario()[this.getX()][this.getY()]==TipoElemento.Espaco){//escrever
					this.EscreverArquivo(c);
					c.getCenario()[this.getX()-1][this.getY()]=TipoElemento.EspacoVazio;
					c.getCenario()[this.getX()][this.getY()]=this.getTipo();
					control=1;
				}
			}else if(Movimento.up.getValor()==k){
				this.setX(this.getX()-1);
				System.out.println("Move up");
				if(this.getX()<0){
					this.setX(this.getX()+1);
					c.visualizarCenario();
					throw new AcaoInvalidaException(Movimento.up);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.Obstaculo){
					this.EscreverArquivo(c);
					for(Obstaculo o: c.getObstaculos()){
						if(o.getX()==this.getX() && o.getY()==this.getY()){
							if(o.getResistencia()==EResistencia.Fragil)
								c.getCenario()[this.getX()][this.getX()]=TipoElemento.EspacoVazio;
							break;
						}
					}
					this.setX(this.getX()+1);
					c.visualizarCenario();
					if(this.getTipo()==TipoElemento.Aventureiro && c.getTipo()!=TipoCamara.camaraErrada){
						int ponto=((k==0)?3:((k==2)?1:((k==3)?0:2)));
						c.getJoao().mover(ponto,c);
						if(c.getJoao().verificaAventureiro(c))
							c.getJoao().setAcho(true);
						c.getJoao().mover(ponto,c);
						if(c.getJoao().verificaAventureiro(c))
							c.getJoao().setAcho(true);
						System.out.println();
						System.out.print("Aventureiro: ");
					}
					if(this.getTipo()==TipoElemento.JoaoDorminhoco){
						System.out.println();
						System.out.print("João Dorminhoco: ");
					}
						throw new AcaoInvalidaException();
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.JoaoDorminhoco){
					this.setX(this.getX()+1);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.Aventureiro){
					if(this.getTipo()==TipoElemento.JoaoDorminhoco)
					c.getJoao().setAcho(true);
					this.setX(this.getX()+1);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.EspacoVazio||c.getCenario()[this.getX()][this.getY()]==TipoElemento.Espaco){
					this.EscreverArquivo(c);
					c.getCenario()[this.getX()+1][this.getY()]=TipoElemento.EspacoVazio;
					c.getCenario()[this.getX()][this.getY()]=this.getTipo();
					control=1;
				}
			}else if(Movimento.left.getValor()==k){
				this.setY(this.getY()-1);
				System.out.println("Move left");
				if(this.getY()<0){
					this.setY(this.getY()+1);
					c.visualizarCenario();
					throw new AcaoInvalidaException(Movimento.left);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.Obstaculo){
					this.EscreverArquivo(c);
					for(Obstaculo o: c.getObstaculos()){
						if(o.getX()==this.getX() && o.getY()==this.getY()){
							if(o.getResistencia()==EResistencia.Fragil)
								c.getCenario()[this.getX()][this.getX()]=TipoElemento.EspacoVazio;
							break;
						}
					}
					this.setY(this.getY()+1);
					c.visualizarCenario();
					if(this.getTipo()==TipoElemento.Aventureiro && c.getTipo()!=TipoCamara.camaraErrada){
						int ponto=((k==0)?3:((k==2)?1:((k==3)?0:2)));
						c.getJoao().mover(ponto,c);
						if(c.getJoao().verificaAventureiro(c))
							c.getJoao().setAcho(true);
						c.getJoao().mover(ponto,c);
						if(c.getJoao().verificaAventureiro(c))
							c.getJoao().setAcho(true);
						System.out.println();
						System.out.print("Aventureiro: ");
					}
					if(this.getTipo()==TipoElemento.JoaoDorminhoco){
						System.out.println();
						System.out.print("João Dorminhoco: ");
					}
						throw new AcaoInvalidaException();
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.JoaoDorminhoco){
					this.setY(this.getY()+1);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.Aventureiro){
					if(this.getTipo()==TipoElemento.JoaoDorminhoco)
					c.getJoao().setAcho(true);
					this.setY(this.getY()+1);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.EspacoVazio||c.getCenario()[this.getX()][this.getY()]==TipoElemento.Espaco){
					this.EscreverArquivo(c);
					c.getCenario()[this.getX()][this.getY()+1]=TipoElemento.EspacoVazio;
					c.getCenario()[this.getX()][this.getY()]=this.getTipo();
					control=1;
				}
			}else if(Movimento.right.getValor()==k){
				this.setY(this.getY()+1);
				System.out.println("Move right");
				if(this.getY()>=c.getDimensao()){
					this.setY(this.getY()-1);
					c.visualizarCenario();
					throw new AcaoInvalidaException(Movimento.right);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.Obstaculo){
					this.EscreverArquivo(c);
					for(Obstaculo o: c.getObstaculos()){
						if(o.getX()==this.getX() && o.getY()==this.getY()){
							if(o.getResistencia()==EResistencia.Fragil)
								c.getCenario()[this.getX()][this.getX()]=TipoElemento.EspacoVazio;
							break;
						}
					}
					this.setY(this.getY()-1);
					c.visualizarCenario();
					if(this.getTipo()==TipoElemento.Aventureiro && c.getTipo()!=TipoCamara.camaraErrada){
						int ponto=((k==0)?3:((k==2)?1:((k==3)?0:2)));
						c.getJoao().mover(ponto,c);
						if(c.getJoao().verificaAventureiro(c))
							c.getJoao().setAcho(true);
						c.getJoao().mover(ponto,c);
						if(c.getJoao().verificaAventureiro(c))
							c.getJoao().setAcho(true);
						System.out.println();
						System.out.print("Aventureiro: ");
					}
					if(this.getTipo()==TipoElemento.JoaoDorminhoco){
						System.out.println();
						System.out.print("João Dorminhoco: ");
					}
					throw new AcaoInvalidaException();
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.JoaoDorminhoco){
					this.setY(this.getY()-1);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.Aventureiro){
					if(this.getTipo()==TipoElemento.JoaoDorminhoco)
					c.getJoao().setAcho(true);
					this.setY(this.getY()-1);
				}else if(c.getCenario()[this.getX()][this.getY()]==TipoElemento.EspacoVazio||c.getCenario()[this.getX()][this.getY()]==TipoElemento.Espaco){
					this.EscreverArquivo(c);
					c.getCenario()[this.getX()][this.getY()-1]=TipoElemento.EspacoVazio;
					c.getCenario()[this.getX()][this.getY()]=this.getTipo();
					control=1;
				}
			}
			c.visualizarCenario();
		}catch(AcaoInvalidaException e1){
			System.out.println(e1);
		}
	}
	private void EscreverArquivo(Camara c){
		try{
			FileWriter fw = new FileWriter(this.getNameArquivo(),true);
			BufferedWriter bw = new BufferedWriter(fw);
			bw.write(this.getX()+" "+this.getY()+" "+c.getCenario()[this.getX()][this.getY()]);
			bw.newLine();
			bw.close();
			fw.close();
		}catch(IOException e2){
			e2.printStackTrace();
		}
	}
	public void EscreverMemoria(){
		try{
			System.out.println();
			System.out.println("Memoria do aventureiro");
			FileReader fr = new FileReader(this.getNameArquivo());
			BufferedReader br = new BufferedReader(fr);
			String linha = br.readLine();
			while(linha !=null){
				String[] dados = linha.split(" ");
				System.out.println("Objeto "+dados[2]+" posição: x-"+dados[0]+" y-"+dados[1]);
				linha = br.readLine();
			}
			br.close();
			fr.close();
		}catch(FileNotFoundException e3){
			System.out.println(" Arquivo não encontrado");
			e3.printStackTrace();
		}catch(IOException e3){
			System.out.println(" Erro de leitura");
			e3.printStackTrace();
		}
	}
}