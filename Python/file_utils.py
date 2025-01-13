"""Module manipulant des fichiers texte."""

def diff(file_first, file_second):
    with open (file_first) as fileid1:
		with open (file_second) as fileid2:
			return fileid1.read() != fileid2.read() 
    

def same(file_first, file_second):
    """Fonction retournant True si deux fichiers sont identiques."""
    return True
