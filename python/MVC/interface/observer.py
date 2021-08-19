from abc import ABC, abstractmethod


class BeatObserver(ABC):
    @abstractmethod
    def update_beat(self) -> None:
        raise NotImplementedError


class BPMObserver(ABC):
    @abstractmethod
    def update_bpm(self) -> None:
        raise NotImplementedError
