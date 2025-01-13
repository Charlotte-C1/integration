"""Module manipulant des fichiers texte."""

def diff(file_first, file_second):
    """Fonction retournant True si deux fichiers sont différents."""
    with open (file_first, encoding="utf-8") as fileid1:
        with open (file_second, encoding="utf-8") as fileid2:
            return fileid1.read() != fileid2.read() 
    

def same(file_first, file_second):
    """Fonction retournant True si deux fichiers sont pareils."""
    with open (file_first, encoding="utf-8") as fileid1:
        with open (file_second, encoding="utf-8") as fileid2:
            return fileid1.read() == fileid2.read() 
