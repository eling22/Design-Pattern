from abc import ABC, abstractmethod
from .Data import Data


class Observer(ABC):
    @abstractmethod
    def update(self, object: Data):
        pass
