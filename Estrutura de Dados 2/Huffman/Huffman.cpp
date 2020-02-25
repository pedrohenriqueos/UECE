#include<bits/stdc++.h>
using namespace std;

class Heap{
private:
	int size,capacity;
	vector<pair<int,string>> Arr;

	int quant(int i){
		return Arr[i].first;
	}
	string carac(int i){
		return Arr[i].second;
	}
	int parent(int i){
		return (i-1)/2;
	}
	int left(int i){
		return 2*i+1;
	}
	int right(int i){
		return 2*i+2;
	}

	void min_heapify(int i){
		int l = left(i),r = right(i);
		int small = i;
		if(l<size and quant(l)< quant(small))
			small = l;
		if(r<size and quant(r)< quant(small))
			small = r;
		if(small!=i){
			swap(Arr[i],Arr[small]);
			min_heapify(small);
		}
	}
public:
	Heap(int _capacity){
		size = 0;
		capacity = _capacity;
		Arr = vector<pair<int,string>> (capacity);
	}

	int getSize(){
		return size;
	}

	void insertVal(pair<int,string> x){
		int i = size++;
		Arr[i] = x;
		while(i!=0 and quant(parent(i))>quant(i)){
			swap(Arr[i],Arr[parent(i)]);
			i = parent(i);
		}
	}
	pair<int,string> Min_heap(){
		if(size<=0)
			return {INT_MAX,"a"};
		if(size==1)
			return Arr[--size];
		pair<int,string> root = Arr[0];
		Arr[0] = Arr[--size];
		min_heapify(0);
		return root;
	}
};

class Huffman{
private:
	vector<int> Frequencia;
	vector<pair<int,string>> Element;
	vector<string> Bits;
	map<pair<int,string>,int> Map;
	vector<array<int,2>> tree;
	int root,capacity,cnt,tamanho_inicial,tamanho_final;

	int quant(int i){
		return Element[i].first;
	}
	string carac(int i){
		return Element[i].second;
	}
	string bits(int i){
		return Bits[i];
	}
	
	void createID(pair<int,string> node,bool parent = false){
		if(!Map.count(node)){
			Map[node] = Element.size();
			if(parent) root = Element.size();
			Element.push_back(node);
		}
	}
public:

	Huffman(int _capacity){
		tree = vector<array<int,2>>(_capacity,{-1,-1});
		Bits = vector<string> (_capacity);
		capacity = _capacity;
		cnt = 0;
		tamanho_inicial = tamanho_final = 0;
	}

	void SetFrequencia(vector<int> _Frequencia){
		Frequencia = _Frequencia;
	}
	int GetTamanhoInicial(){
		return tamanho_inicial;
	}
	void SetTamanhoInicial(int tamanho){
		tamanho_inicial = tamanho;
	}
	int GetTamanhoFinal(){
		return tamanho_final;
	}
	void SetTamanhoFinal(int tamanho){
		tamanho_final = tamanho;
	}
	int getRoot(){
		return root;
	}
	
	void insertRoot(pair<int,string> parent){
		createID(parent,true);
	}
	//insere os elementos na árvore
	void insertElement(pair<int,string> parent,pair<int,string> left,pair<int,string> right){
		createID(parent,true);
		createID(left);
		createID(right);
		tree[Map[parent]] = {Map[left],Map[right]};
	}
	//define os bits para cada caractere
	void construct_huffman(int id,string bits){
		int left = tree[Map[Element[id]]][0];
		int right = tree[Map[Element[id]]][1];
		if(left==-1 and right==-1){
			if(id==getRoot() and bits=="")
				bits.push_back('0');
			Bits[id] = bits;
			SetTamanhoFinal(GetTamanhoFinal()+bits.size()*Frequencia[carac(id)[0]]);
		}
		if(left!=-1)
			construct_huffman(left,bits+'0');
		if(right!=-1)
			construct_huffman(right,bits+'1');
	}
	//busca o elemento-> find(this.getRoot(),busca)
	string find(int id,char busca){
		if(carac(id).size()==1){
			if(carac(id)[0]==busca)
				return bits(id);
			else
				return "not found!";
		}
		int left = tree[Map[Element[id]]][0];
		int right = tree[Map[Element[id]]][1];
		bool sentido = false;
		if(left!=-1)
			for(auto c:carac(left))
				if(c==busca){
					sentido = true;
					break;
				}
		if(sentido)
			return find(left,busca);
		if(right!=-1)
			return find(right,busca);
		else
			return "not found!";
	}

	void print_tree(int id){
		string aux(cnt,' ');
		cout  << aux << quant(id) << " " << carac(id) << " " << bits(id) << '\n';
		int left = tree[Map[Element[id]]][0];
		int right = tree[Map[Element[id]]][1];
		if(left!=-1){
			cnt+=4;
			print_tree(left);
			cnt-=4;
		}
		if(right!=-1){
			cnt+=4;
			print_tree(right);
			cnt-=4;
		}
	}
	void print_bits(){
		for(int id=0;id<Element.size();id++)
			if(carac(id).size()==1)
				cout << quant(id) << " '" << carac(id) << "' " << bits(id) << '\n'; 
	}
};

int main(){
	string txt="";
	vector<int> Frequencia(257);
	bool checkfile = false;
	while(getline(cin,txt)){
		for(auto c:txt)
			Frequencia[c]++;
		Frequencia['\n']++;
		checkfile = true;
	}
	if(!checkfile){
		cout << "Não houve arquivo de entrada para a compressão.\n";
		exit(1);
	}
	vector<pair<int,string>> Elements;
	for(int i=0;i<257;i++)
		if(Frequencia[i])
			Elements.push_back({Frequencia[i],string(1,(char)i)});
	Heap heap(Elements.size());
	Huffman huff(2*Elements.size());
	huff.SetFrequencia(Frequencia);
	for(auto element:Elements)
		heap.insertVal(element);
	if(heap.getSize()==1){
		auto element = heap.Min_heap();
		huff.insertRoot(element);
		huff.SetTamanhoInicial(huff.GetTamanhoInicial()+8*Frequencia[element.second[0]]);
	}
	//seleciona os elementos com menor frequencia
	while(heap.getSize()>1){
		auto element1 = heap.Min_heap();
		auto element2 = heap.Min_heap();
		auto new_element = make_pair(element1.first+element2.first,element1.second+element2.second);
		if(element1.second.size()==1)
			huff.SetTamanhoInicial(huff.GetTamanhoInicial()+8*Frequencia[element1.second[0]]);
		if(element2.second.size()==1)
			huff.SetTamanhoInicial(huff.GetTamanhoInicial()+8*Frequencia[element2.second[0]]);
		huff.insertElement(new_element,element1,element2);
		heap.insertVal(new_element);
	}
	auto element = heap.Min_heap();
	string bit="";
	huff.construct_huffman(huff.getRoot(),bit);
	huff.print_tree(huff.getRoot());
	huff.print_bits();
	cout << "Compressão de " << huff.GetTamanhoInicial() << " bits. Para " << huff.GetTamanhoFinal() << " bits.\n";
	cout << "Otimização de " << 100.0-(((double)huff.GetTamanhoFinal()*100)/(double)huff.GetTamanhoInicial()) << "%\n";
	return 0;
}
