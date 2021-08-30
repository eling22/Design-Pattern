from view import View
from interface.beat_model_interface import BeatModelInterface
from interface.controller import ControllerInterface


class BeatController(ControllerInterface):
    def __init__(self, model: BeatModelInterface) -> None:
        super().__init__()
        self.model = model
        self.view = View(self, model)
        self.view.create_view()

    def start(self) -> None:
        self.model.on()
        # self.view

    def stop(self) -> None:
        pass

    def increase_bmp(self) -> None:
        pass

    def decrease_bmp(self) -> None:
        pass

    def set_bpm(self, bpm: int):
        pass
