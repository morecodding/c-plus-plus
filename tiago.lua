-- comentarios..
-- table.maxn(<nome do vetor>) - size da tabela
-- string.len(<palavra>) - tamanho da palavra
-- io.write(<o que quer escrever>) - printa numa linha somente
-- ~= - diferente de 


text = { }
text_mascarado = { }
pontos = 0


print "jogo da forca"

function armazena_palavra()
	-- le a palavra
	palavra = io.read()
	palavra = io.read("*line")

	-- insere a palavra no vetor text
	for i = 1, string.len(palavra) do
	    table.insert(text, i, string.sub(palavra, i, i))
	    table.insert(text_mascarado, '-')
	    pontos = pontos + 1
	end
end

function printa_xablau(v, i)
	for i = 1, table.maxn(v) do
		io.write(v[i])
	end
	if(i == 1) then
		print ()
	end
end

function jogo_de_verdade()
	-- um jogador escolhe uma letra
	-- se essa letra estiver na palavra
	--		escreve letra
	-- senao 
	-- 		perde ponto == desenha forca

	io.write("digite uma letra: ")
	letra = io.read("*line") 

	indices_da_palavra = { }
	contains = 0
	for i = 1, table.maxn(text) do
		if (letra == text[i]) then
			contains = 1
			table.insert(indices_da_palavra, i)
		end
	end

	if (contains == 1) then
		for i = 1, table.maxn(indices_da_palavra) do
			table.insert(text_mascarado, indices_da_palavra[i], text[indices_da_palavra[i]])
		end
	else
		pontos = pontos - 1
	end
end

function inicio()
	print "jogando..."
	a = 0;
	while ( a ~= -1 ) do
		print "para iniciar digite 1:\npara sair digite -1"
		a = io.read("*number")

		if(a == 1) then
			print "digite uma palavra"
			armazena_palavra()
			while(pontos ~= 0)  do
				printa_xablau(text_mascarado, 1)
				jogo_de_verdade()
			end
		end

		if(a == -1) then
			print "voce saiu do jogo"
		end

	end
end


-- o que consiste o jogo da forca?
-- 
-- palavra
-- pega a palavra e separa as letras
-- um jogador escolhe uma letra
-- se essa letra estiver na palavra
--		escreve letra
-- senao 
-- 		perde ponto == desenha forca
-- 
-- o jogo acaba, quando o jogador acerta todas as letras ou a forca esta completa == pontos = 0

-- O que falta?
-- verificar quando a palavra terminou de ser preenchida,
-- use uma outra flag para isso
-- no loop while adicionar a veriricaçao dessa flag


inicio()
