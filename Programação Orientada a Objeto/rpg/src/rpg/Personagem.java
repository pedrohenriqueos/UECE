package rpg;

public abstract class Personagem extends Elemento{
	private int x,y;
	
	public Personagem(TipoElemento tipo){
		super(tipo);
	}
	
	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public void mover(int k,Camara c) throws AcaoInvalidaException{
		System.out.println();
		for(int j=0;j<c.getDimensao();j++)
			System.out.print("------");
		System.out.println();
		
		if(this.getTipo()==TipoElemento.Aventureiro)
			System.out.print("Aventureiro ");
		else
			System.out.print("JoaoD ");
		try{
			if(Movimento.down.getValor()==k){
				x++;
				System.out.println("Move down");
				if(x>=c.getDimensao()){
					x--;
					c.visualizarCenario();
					throw new AcaoInvalidaException(Movimento.down);
				}else if(c.getCenario()[x][y]==TipoElemento.Obstaculo){
					x--;
					c.visualizarCenario();
					if(this.getTipo()==TipoElemento.Aventureiro && c.getTipo()!=TipoCamara.camaraErrada){
						c.getJoao().setEstado(Estado.acordado);
						int ponto=((k==0)?3:((k==2)?1:((k==3)?0:2)));
						c.getJoao().setMove(ponto);
						System.out.println();
						System.out.print("Aventureiro: ");
					}
					if(this.getTipo()==TipoElemento.JoaoDorminhoco){
						System.out.println();
						System.out.print("João Dorminhoco: ");
					}
						throw new AcaoInvalidaException();
				}else if(c.getCenario()[x][y]==TipoElemento.JoaoDorminhoco){
					x--;
					if(c.getJoao().getEstado()==Estado.acordado)
						c.getJoao().setAcho(true);
				}else if(c.getCenario()[x][y]==TipoElemento.Aventureiro){
					if(this.getTipo()==TipoElemento.JoaoDorminhoco)
						c.getJoao().setAcho(true);
					x--;
				}else if(c.getCenario()[x][y]==TipoElemento.EspacoVazio||c.getCenario()[x][y]==TipoElemento.Espaco){
					c.getCenario()[x-1][y]=TipoElemento.EspacoVazio;
					c.getCenario()[x][y]=this.getTipo();
				}
			}else if(Movimento.up.getValor()==k){
				x--;
				System.out.println("Move up");
				if(x<0){
					x++;
					c.visualizarCenario();
					throw new AcaoInvalidaException(Movimento.up);
				}else if(c.getCenario()[x][y]==TipoElemento.Obstaculo){
					x++;
					c.visualizarCenario();
					if(this.getTipo()==TipoElemento.Aventureiro && c.getTipo()!=TipoCamara.camaraErrada){
						c.getJoao().setEstado(Estado.acordado);
						int ponto=((k==0)?3:((k==2)?1:((k==3)?0:2)));
						c.getJoao().setMove(ponto);
						System.out.println();
						System.out.print("Aventureiro: ");
					}
					if(this.getTipo()==TipoElemento.JoaoDorminhoco){
						System.out.println();
						System.out.print("João Dorminhoco: ");
					}
						throw new AcaoInvalidaException();
				}else if(c.getCenario()[x][y]==TipoElemento.JoaoDorminhoco){
					x++;
					if(c.getJoao().getEstado()==Estado.acordado)
						c.getJoao().setAcho(true);
				}else if(c.getCenario()[x][y]==TipoElemento.Aventureiro){
					if(this.getTipo()==TipoElemento.JoaoDorminhoco)
					c.getJoao().setAcho(true);
					x++;
				}else if(c.getCenario()[x][y]==TipoElemento.EspacoVazio||c.getCenario()[x][y]==TipoElemento.Espaco){
					c.getCenario()[x+1][y]=TipoElemento.EspacoVazio;
					c.getCenario()[x][y]=this.getTipo();
				}
			}else if(Movimento.left.getValor()==k){
				y--;
				System.out.println("Move left");
				if(y<0){
					y++;
					c.visualizarCenario();
					throw new AcaoInvalidaException(Movimento.left);
				}else if(c.getCenario()[x][y]==TipoElemento.Obstaculo){
					y++;
					c.visualizarCenario();
					if(this.getTipo()==TipoElemento.Aventureiro && c.getTipo()!=TipoCamara.camaraErrada){
						c.getJoao().setEstado(Estado.acordado);
						int ponto=((k==0)?3:((k==2)?1:((k==3)?0:2)));
						c.getJoao().setMove(ponto);
						System.out.println();
						System.out.print("Aventureiro: ");
					}
					if(this.getTipo()==TipoElemento.JoaoDorminhoco){
						System.out.println();
						System.out.print("João Dorminhoco: ");
					}
						throw new AcaoInvalidaException();
				}else if(c.getCenario()[x][y]==TipoElemento.JoaoDorminhoco){
					y++;
					if(c.getJoao().getEstado()==Estado.acordado)
						c.getJoao().setAcho(true);
				}else if(c.getCenario()[x][y]==TipoElemento.Aventureiro){
					if(this.getTipo()==TipoElemento.JoaoDorminhoco)
					c.getJoao().setAcho(true);
					y++;
				}else if(c.getCenario()[x][y]==TipoElemento.EspacoVazio||c.getCenario()[x][y]==TipoElemento.Espaco){
					c.getCenario()[x][y+1]=TipoElemento.EspacoVazio;
					c.getCenario()[x][y]=this.getTipo();
				}
			}else if(Movimento.right.getValor()==k){
				y++;
				System.out.println("Move right");
				if(y>=c.getDimensao()){
					y--;
					c.visualizarCenario();
					throw new AcaoInvalidaException(Movimento.right);
				}else if(c.getCenario()[x][y]==TipoElemento.Obstaculo){
					y--;
					c.visualizarCenario();
					if(this.getTipo()==TipoElemento.Aventureiro && c.getTipo()!=TipoCamara.camaraErrada){
						c.getJoao().setEstado(Estado.acordado);
						int ponto=((k==0)?3:((k==2)?1:((k==3)?0:2)));
						c.getJoao().setMove(ponto);
						System.out.println();
						System.out.print("Aventureiro: ");
					}
					if(this.getTipo()==TipoElemento.JoaoDorminhoco){
						System.out.println();
						System.out.print("João Dorminhoco: ");
					}
					throw new AcaoInvalidaException();
				}else if(c.getCenario()[x][y]==TipoElemento.JoaoDorminhoco){
					y--;
					if(c.getJoao().getEstado()==Estado.acordado)
						c.getJoao().setAcho(true);
				}else if(c.getCenario()[x][y]==TipoElemento.Aventureiro){
					if(this.getTipo()==TipoElemento.JoaoDorminhoco)
					c.getJoao().setAcho(true);
					y--;
				}else if(c.getCenario()[x][y]==TipoElemento.EspacoVazio||c.getCenario()[x][y]==TipoElemento.Espaco){
					c.getCenario()[x][y-1]=TipoElemento.EspacoVazio;
					c.getCenario()[x][y]=this.getTipo();
				}
			}
			c.visualizarCenario();
		}catch(AcaoInvalidaException e1){
			System.out.println(e1);
		}
	}
}