const btns = document.getElementsByClassName("btn");

Array.prototype.slice.call(btns).forEach((btn) =>
  btn.addEventListener("click", function (e) {
    this.nextElementSibling.classList.toggle("open");
  })
);