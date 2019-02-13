package rpg;

public class Aventureiro extends Personagem{
	public Aventureiro(){
		super(TipoElemento.Aventureiro);
	}
	public boolean encontrouTesouro(Camara a){
		return ((this.getX()==a.getDimensao()-3 && this.getY()==a.getDimensao()-1 &&((a.getCenario()[this.getX()+1][this.getY()]==TipoElemento.EspacoVazio)||(a.getCenario()[this.getX()+1][this.getY()]==TipoElemento.Espaco)))||(this.getX()==a.getDimensao()-1 && this.getY()==a.getDimensao()-3 &&(a.getCenario()[this.getX()][this.getY()+1]==TipoElemento.EspacoVazio||a.getCenario()[this.getX()][this.getY()+1]==TipoElemento.Espaco))
				||(this.getX()==a.getDimensao()-2 && this.getY()==a.getDimensao()-1)||(this.getX()==a.getDimensao()-1 && this.getY()==a.getDimensao()-2));
	}
	public boolean encontrouMensagem(Camara a){
		return ((this.getX()==a.getDimensao()-3 && this.getY()==a.getDimensao()-1 &&((a.getCenario()[this.getX()+1][this.getY()]==TipoElemento.EspacoVazio)||(a.getCenario()[this.getX()+1][this.getY()]==TipoElemento.Espaco)))||(this.getX()==a.getDimensao()-1 && this.getY()==a.getDimensao()-3 &&(a.getCenario()[this.getX()][this.getY()+1]==TipoElemento.EspacoVazio||a.getCenario()[this.getX()][this.getY()+1]==TipoElemento.Espaco))
				||(this.getX()==a.getDimensao()-2 && this.getY()==a.getDimensao()-1)||(this.getX()==a.getDimensao()-1 && this.getY()==a.getDimensao()-2));
	}
}
