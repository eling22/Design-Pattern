import tkinter as tk


class View:
    def __init__(self) -> None:
        pass

    def create(self):
        window = tk.Tk()
        window.title("window")
        align_mode = "nswe"
        init_size = 250

        view_frame = tk.Frame(window, bg="orange", width=init_size, height=init_size)
        view_frame.grid(column=0, row=0, sticky=align_mode)

        bpm_frame = tk.Frame(window, bg="yellow", width=init_size, height=init_size)
        bpm_frame.grid(column=1, row=0, sticky=align_mode)

        window.columnconfigure(0, weight=1)
        window.columnconfigure(1, weight=1)
        window.rowconfigure(0, weight=1)

        window.mainloop()
