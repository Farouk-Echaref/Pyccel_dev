class Fecha:
    def __init__(self, atr) -> None:
        self._atr = atr
    
    @property
    def atr(self):
        return self._atr

    @atr.setter
    def atr(self, new_atr):
        if (new_atr > 5):
            self._atr = new_atr
    

fech = Fecha(5)
print(fech.atr)
fech.atr = 69
print(fech.atr)