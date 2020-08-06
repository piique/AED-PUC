# Script usado para excluir arquivos executaveis gerados pelo gcc e executaveis .exe

cd ..
find ./ -type f -path "./Lista*/*" ! -name "*.*"  -delete
find ./ -type f -path "./Lista*/*" -name "*.exe"  -delete

## Teste: 
# find ./ -type f -path "./Lista*/*" ! -name "*.*" 
# find ./ -type f -path "./Lista*/*" -name "*.exe" 

## Exemplos:
# find . -path ./.git -prune -o -type f  ! -name "*.*"
# find ./ -type f -not -path "./.*/*" ! -name "*.*"
