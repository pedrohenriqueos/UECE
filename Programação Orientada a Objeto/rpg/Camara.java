package rpg;

import java.util.Random;

public class Camara {
	private TipoElemento[][] cenario;
	private int dimensao;
	private TipoCamara tipo;
	private Aventureiro aventureiro;
	private JoaoDorminhoco Joao;
	public Camara(int dimensao){
		this.setCenario(new TipoElemento[dimensao][dimensao]);
		this.dimensao = dimensao;
	}
	public Aventureiro getAventureiro() {
		return aventureiro;
	}

	public void setAventureiro(Aventureiro aventureiro) {
		this.aventureiro = aventureiro;
	}

	public JoaoDorminhoco getJoao() {
		return Joao;
	}

	public void setJoao(JoaoDorminhoco joao) {
		Joao = joao;
	}

	public void setDimensao(int dimensao){
		this.dimensao = dimensao;
	}
	public TipoElemento[][] getCenario(){
		return cenario;
	}
	public int getDimensao(){
		return this.dimensao;
	}
	public void setCenario(TipoElemento[][] cenario) {
		this.cenario = cenario;
	}
	public TipoCamara getTipo(){
		return this.tipo;
	}
	public void setTipo(TipoCamara tipo) {
		this.tipo = tipo;
	}
	public void Iniciar(TipoCamara camara,Aventureiro aventureiro,JoaoDorminhoco Joao){
		this.setTipo(camara);
		this.setAventureiro(aventureiro);
		this.setJoao(Joao);
		this.getAventureiro().setX(0);
		this.getAventureiro().setY(0);
		for(int i=0;i<this.getDimensao();i++)
			for(int j=0;j<this.getDimensao();j++)
				this.getCenario()[i][j] = TipoElemento.EspacoVazio;
		
		this.getCenario()[0][0] = TipoElemento.Aventureiro;
		this.getCenario()[0][1] = TipoElemento.Espaco;
		this.getCenario()[1][0] = TipoElemento.Espaco;
		this.getCenario()[1][1] = TipoElemento.Espaco;
		this.getCenario()[this.getDimensao()-1][this.getDimensao()-2] = TipoElemento.Espaco;
		this.getCenario()[this.getDimensao()-2][this.getDimensao()-1] = TipoElemento.Espaco;
		this.getCenario()[this.getDimensao()-2][this.getDimensao()-2] = TipoElemento.Espaco;
		switch(camara){
		case camaraFacil:
			this.getCenario()[this.dimensao-1][this.dimensao-1] = TipoElemento.Tesouro;
			break;
		case camaraDificil:
			this.getCenario()[this.dimensao-1][this.dimensao-1] = TipoElemento.Tesouro;
			Random num1 = new Random();
			Random num2 = new Random();
			boolean ok =false,saida1=false;
			int a=0,b=0;
			while(!saida1){
				a = num1.nextInt(this.dimensao);b=num2.nextInt(this.dimensao);
				if(this.getCenario()[a][b]==TipoElemento.EspacoVazio){
					this.getCenario()[a][b] = TipoElemento.JoaoDorminhoco;
					this.getJoao().setX(a);
					this.getJoao().setY(b);
					saida1 = true;
				}else{
					num1 = new Random();
					num2 = new Random();
				}
			}
			num1 = new Random();
			num2 = new Random();
			if(this.dimensao/2>=4){
				for(int i=0;i<this.dimensao/2;i++){
					ok=false;
					while(!ok){
						int o1 = num1.nextInt(this.dimensao),o2=num2.nextInt(this.dimensao);
						if((o1!=a+1 && o2!=b)&&(o1!=a && o2!=b+1)&&(o1!=a-1 && o2!=b)&&(o1!=a && o2!=b-1)&&this.getCenario()[o1][o2]==TipoElemento.EspacoVazio){
							this.getCenario()[o1][o2] = TipoElemento.Obstaculo;
							ok=true;
						}else{
							num1 = new Random();
							num2 = new Random();
						}
					}
				}
			}else{
				for(int i=0;i<this.dimensao/2;i++){
					ok=false;
					while(!ok){
						int o1 = num1.nextInt(this.dimensao),o2=num2.nextInt(this.dimensao);
						if(this.getCenario()[o1][o2]==TipoElemento.EspacoVazio){
							this.getCenario()[o1][o2] = TipoElemento.Obstaculo;
							ok=true;
						}else{
							num1 = new Random();
							num2 = new Random();
						}
					}
				}
			}
			break;
		case camaraErrada:
			this.getCenario()[this.dimensao-1][this.dimensao-1] = TipoElemento.Mensagem;
			Random num21 = new Random();
			Random num22 = new Random();
			boolean ok2=false;
			int a1=0,b1=0;
			if(this.dimensao/2>=4){
				for(int i=0;i<this.dimensao/2;i++){
					ok2=false;
					while(!ok2){
						int o21 = num21.nextInt(this.dimensao),o22=num22.nextInt(this.dimensao);
						if((o21!=a1+1 && o22!=b1)&&(o21!=a1 && o22!=b1+1)&&(o21!=a1-1 && o22!=b1)&&(o21!=a1 && o22!=b1-1)&&this.getCenario()[o21][o22]==TipoElemento.EspacoVazio){
							this.getCenario()[o21][o22] = TipoElemento.Obstaculo;
							ok2=true;
						}else{
							num21 = new Random();
							num22 = new Random();
						}
					}
				}
			}else{
				for(int i=0;i<this.dimensao/2;i++){
					ok2=false;
					while(!ok2){
						int o21 = num21.nextInt(this.dimensao),o22=num22.nextInt(this.dimensao);
						if(this.getCenario()[o21][o22]==TipoElemento.EspacoVazio){
							this.getCenario()[o21][o22] = TipoElemento.Obstaculo;
							ok2=true;
						}else{
							num1 = new Random();
							num2 = new Random();
						}
					}
				}
			}
			break;
		}
		
	}
	public void visualizarCenario(){
		for(int i=0;i<this.dimensao;i++){
			for(int j=0;j<this.dimensao;j++){
				if(this.getCenario()[i][j]== TipoElemento.Aventureiro){
					System.out.print(" Av  ;");
				}else if(this.getCenario()[i][j]== TipoElemento.EspacoVazio ||this.getCenario()[i][j]== TipoElemento.Espaco){
					System.out.print("     ;");
				}else if(this.getCenario()[i][j]== TipoElemento.JoaoDorminhoco){
					System.out.print("JoaoD;");
				}else if(this.getCenario()[i][j]== TipoElemento.Obstaculo){
					System.out.print("Obsta;");
				}else if(this.getCenario()[i][j]==TipoElemento.Tesouro){
					System.out.print("tesou;");
				}else{
					System.out.print("mensa;");
				}
			}
			System.out.println();
		}
	}
}