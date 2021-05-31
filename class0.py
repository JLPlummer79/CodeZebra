#class0.py classes in Python

class PartyAnimal:
    x = 0
    def party(self):
        self.x = self.x + 2
        print("So far", self.x)

an = PartyAnimal()
an.party()
an.party()

