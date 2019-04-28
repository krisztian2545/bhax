(defun factorial (N)
  "Compute the factorial of N."
  (if (= N 1)
      1
    (* N (factorial (- N 1)))))

(FACTORIAL 5)

(= M 5)
(= F M)

(loop for I from 4 to 2
   (= F (* F I))
)
do (print F)