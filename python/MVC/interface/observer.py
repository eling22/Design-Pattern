from abc import ABCMeta, abstractmethod


class BeatObserver(ABCMeta):
    @abstractmethod
    def update_beat(self) -> None:
        raise NotImplementedError


class BPMObserver(ABCMeta):
    @abstractmethod
    def update_bpm(self) -> None:
        raise NotImplementedError
