(do ((n 1 (1+ n))
	 (l 1 (* n l)))
    ((= 6 n)
     l)
  )

(defun factorial (N)
  (if (= N 1)
      1
    (* N (factorial (- N 1)))))

(FACTORIAL 5)