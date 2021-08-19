from abc import ABC, abstractmethod
from interface.observer import BPMObserver, BeatObserver


class BeatModelInterface(ABC):
    @abstractmethod
    def initialize(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def on(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def off(self) -> None:
        raise NotImplementedError

    @abstractmethod
    def set_bpm(self, bpm: int):
        raise NotImplementedError

    @abstractmethod
    def get_bpm(self) -> int:
        raise NotImplementedError

    def register_observer(self, observer: BeatObserver) -> None:
        if isinstance(observer, BeatObserver):
            self.register_beat_observer(observer)
        elif isinstance(observer, BPMObserver):
            self.register_bpm_observer(observer)

    def remove_observer(self, observer: BeatObserver) -> None:
        if isinstance(observer, BeatObserver):
            self.remove_beat_observer(observer)
        elif isinstance(observer, BPMObserver):
            self.remove_bpm_observer(observer)

    @abstractmethod
    def register_beat_observer(self, observer: BeatObserver) -> None:
        raise NotImplementedError

    @abstractmethod
    def remove_beat_observer(self, observer: BeatObserver) -> None:
        raise NotImplementedError

    @abstractmethod
    def register_bpm_observer(self, observer: BPMObserver) -> None:
        raise NotImplementedError

    @abstractmethod
    def remove_bpm_observer(self, observer: BPMObserver) -> None:
        raise NotImplementedError
