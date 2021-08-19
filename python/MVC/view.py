from interface.beat_model_interface import BeatModelInterface
from interface.observer import BPMObserver, BeatObserver
import tkinter as tk
from tkinter import StringVar, ttk
import time


class View(BeatObserver, BPMObserver):
    def __init__(self, model: BeatModelInterface) -> None:
        self.model = model
        self.l_bpm_num: StringVar
        self.model.register_beat_observer(self)
        self.model.register_bpm_observer(self)

    def create_view(self):
        init_size = 250

        window = tk.Tk()
        window.title("window")
        self.window = window

        self.create_view_frame_obj(init_size)
        self.create_bpm_frame_obj(init_size)
        self.create_menu()

        window.columnconfigure(0, weight=1)
        window.columnconfigure(1, weight=1)
        window.rowconfigure(0, weight=1)

        window.mainloop()

    def create_menu(self):
        menubar = tk.Menu(self.window)
        control_menu = tk.Menu(menubar, tearoff=0)
        control_menu.add_command(label="Start", command=self.do_nothing)
        control_menu.add_command(label="Stop", command=self.do_nothing)
        control_menu.add_command(label="Quit", command=self.do_nothing)
        menubar.add_cascade(label="DJ Control", menu=control_menu)
        self.window.config(menu=menubar)

    def create_view_frame_obj(self, init_size):
        align_mode = "nswe"
        # fmt: off
        view_frame = tk.Frame(self.window, width=init_size, height=init_size / 1.6)
        view_frame.grid(column=0, row=0, sticky=align_mode)

        self.pulsing_bar = ttk.Progressbar(view_frame, orient="horizontal", mode="determinate", length=200)
        self.pulsing_bar.grid(column=0, row=0, columnspan=2, padx=10, pady=20)

        self.l_bpm_num = tk.StringVar()
        self.l_bpm_num.set("Current BPM: 0")
        tk.Label(view_frame, textvariable=self.l_bpm_num, font=("Helvetica", 16))\
            .grid(column=0, row=1, columnspan=2, padx=10, pady=10)
        # fmt: on

    def create_bpm_frame_obj(self, init_size):
        align_mode = "nswe"

        # fmt: off
        bpm_frame = tk.Frame(self.window, width=init_size, height=init_size / 1.6)
        bpm_frame.grid(column=1, row=0, sticky=align_mode)
        
        self.l_enter_bpm = tk.Label(bpm_frame, text="Enter BPM:", font=("Helvetica", 12))
        self.l_enter_bpm.grid(column=0, row=1, padx=10, pady=5, sticky=align_mode)

        self.bmp_var = tk.StringVar()
        self.bmp_entry = ttk.Entry(bpm_frame, textvariable=self.bmp_var)
        self.bmp_entry.grid(column=1, row=1, padx=10, pady=5, sticky=align_mode)

        self.btn_set = tk.Button(bpm_frame, text="Set", command=self.btn_set_click)
        self.btn_set.grid(column=0, row=2, columnspan=2, padx=10, pady=10, sticky=align_mode)

        self.btn_dec = tk.Button(bpm_frame, text="<<", command=self.btn_set_click, width=15)
        self.btn_dec.grid(column=0, row=3, padx=10, pady=10, sticky=align_mode)

        self.btn_inc = tk.Button(bpm_frame, text=">>", command=self.btn_set_click, width=15)
        self.btn_inc.grid(column=1, row=3, padx=10, pady=10, sticky=align_mode)
        # fmt: on

    def btn_set_click(self):
        for i in range(5):
            self.window.update_idletasks()
            self.pulsing_bar["value"] += 20
            time.sleep(1)
            self.window.update_idletasks()
            self.pulsing_bar["value"] -= 10
            time.sleep(1)

    def do_nothing(self):
        filewin = tk.Toplevel(self.window)
        button = tk.Button(filewin, text="Do nothing button")
        button.pack()

    def update_beat(self) -> None:
        bpm = self.model.get_bpm()
        if bpm == 0:
            self.l_bpm_num.set("offline")
        else:
            self.l_bpm_num.set(f"Current BPM: {bpm}")

    def update_bpm(self) -> None:
        raise NotImplementedError
