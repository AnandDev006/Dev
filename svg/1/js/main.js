const rect = document.getElementById("rect");
rect.addEventListener("mouseenter", function () {
  this.classList.add("magic");
});
rect.addEventListener("mouseleave", function () {
  this.classList.remove("magic");
});
