import tkinter as tk
from tkinter import ttk
import time


class View:
    def __init__(self) -> None:
        pass

    def create(self):
        align_mode = "nswe"
        init_size = 250

        window = tk.Tk()
        window.title("window")
        self.window = window

        menubar = tk.Menu(window)
        control_menu = tk.Menu(menubar, tearoff=0)
        control_menu.add_command(label="Start", command=self.donothing)
        control_menu.add_command(label="Stop", command=self.donothing)
        control_menu.add_command(label="Quit", command=self.donothing)
        menubar.add_cascade(label="DJ Control", menu=control_menu)

        view_frame = tk.Frame(window, width=init_size, height=init_size / 1.6)
        view_frame.grid(column=0, row=0, sticky=align_mode)

        bpm_frame = tk.Frame(window, width=init_size, height=init_size / 1.6)
        bpm_frame.grid(column=1, row=0, sticky=align_mode)

        window.columnconfigure(0, weight=1)
        window.columnconfigure(1, weight=1)
        window.rowconfigure(0, weight=1)

        self.create_view_frame_obj(view_frame)
        self.create_bpm_frame_obj(bpm_frame)

        window.config(menu=menubar)
        window.mainloop()

    def create_view_frame_obj(self, frame):
        # fmt: off
        self.pulsing_bar = ttk.Progressbar(frame, orient="horizontal", mode="determinate", length=200)
        self.pulsing_bar.grid(column=0, row=0, columnspan=2, padx=10, pady=20)

        self.l_bpm_num = tk.Label(frame, text="Current BPM: 0", font=("Helvetica", 16))
        self.l_bpm_num.grid(column=0, row=1, columnspan=2, padx=10, pady=10)
        # fmt: on

    def create_bpm_frame_obj(self, frame):
        align_mode = "nswe"

        # fmt: off
        self.l_enter_bpm = tk.Label(frame, text="Enter BPM:", font=("Helvetica", 12))
        self.l_enter_bpm.grid(column=0, row=1, padx=10, pady=5, sticky=align_mode)

        self.bmp_var = tk.StringVar()
        self.bmp_entry = ttk.Entry(frame, textvariable=self.bmp_var)
        self.bmp_entry.grid(column=1, row=1, padx=10, pady=5, sticky=align_mode)

        self.btn_set = tk.Button(frame, text="Set", command=self.btn_set_click)
        self.btn_set.grid(column=0, row=2, columnspan=2, padx=10, pady=10, sticky=align_mode)

        self.btn_dec = tk.Button(frame, text="<<", command=self.btn_set_click, width=15)
        self.btn_dec.grid(column=0, row=3, padx=10, pady=10, sticky=align_mode)

        self.btn_inc = tk.Button(frame, text=">>", command=self.btn_set_click, width=15)
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

    def donothing(self):
        filewin = tk.Toplevel(self.window)
        button = tk.Button(filewin, text="Do nothing button")
        button.pack()
