
REM cd ..
REM set /p f=Deseja excluir todos os arquivos .exe, .ilk e .del dentro do diretorio: %CD%? (S/n): 
REM IF %f%=="s" IF %f%=="S" (
REM )
echo deletando arquivos .exe, .ilk, .pdb
del /s /q .\..\*.exe && del /s /q .\..\*.ilk && del /s /q .\..\*.pdb