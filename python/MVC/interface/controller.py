from abc import ABC, abstractmethod


class ControllerInterface(ABC):
    @abstractmethod
    def start(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def stop(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def increase_bpm(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def decrease_bpm(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def set_bpm(self, bpm: int):
        raise NotImplementedError
