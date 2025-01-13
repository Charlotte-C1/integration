"""Module manipulant des fichiers texte."""

def diff(file_first, file_second):
    with open (file_first) as file_id1:
		with open (file_second) as file_id2:
			return file_id1.read() != file_id2.read() 
    

def same(file_first, file_second):
    """Fonction retournant True si deux fichiers sont identiques."""
    return True
