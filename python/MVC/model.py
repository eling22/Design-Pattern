from typing import List
from interface.beat_model_interface import BeatModelInterface
from interface.observer import BPMObserver, BeatObserver


class BeatModel(BeatModelInterface):
    def __init__(self) -> None:
        self.bpm: int = 0
        self.beat_observer_list: List[BeatObserver] = []
        self.bpm_observer_list: List[BPMObserver] = []

    def initialize(self) -> None:
        pass

    def on(self) -> None:
        print("beat start")

    def off(self) -> None:
        print("beat stop")

    def set_bpm(self, bpm: int):
        if bpm >= 0 and bpm <= 100:
            self.bpm = bpm
            self.notify_bpm_observers()

    def get_bpm(self) -> int:
        return self.bpm

    def register_beat_observer(self, observer: BeatObserver) -> None:
        if observer not in self.beat_observer_list:
            self.beat_observer_list.append(observer)

    def remove_beat_observer(self, observer: BeatObserver) -> None:
        self.beat_observer_list.remove(observer)

    def notify_beat_observers(self) -> None:
        for observer in self.beat_observer_list:
            observer.update_beat()

    def register_bpm_observer(self, observer: BPMObserver) -> None:
        if observer not in self.bpm_observer_list:
            self.bpm_observer_list.append(observer)

    def remove_bpm_observer(self, observer: BPMObserver) -> None:
        self.bpm_observer_list.remove(observer)

    def notify_bpm_observers(self) -> None:
        for observer in self.bpm_observer_list:
            observer.update_bpm()
