#lang racket
;; A01701350 Jorge Alan Ramirez Elias 
;; A01701490 Paulina Cardoso Fuentes

;;(enter! (file "act.rkt"))

;;Ejercicio 1 Farenheit Celcius

(define (f-c f)
  (/ (* 5 (- f 32)) 9))

;;Sign

(define(sign a)
  (cond
    [(= a 0) 0]
    [(< a 0) -1]
    [else 1]))
;;Roots

(define(roots a b c)
  (/ (+ (- b)(sqrt (- (* b b) (* 4 a c))))(* 2 a)))

;;BMI
(define (print_bmi b)
  (cond
    [(< b 20) (string #\u #\n #\d #\e #\r #\w #\e #\i #\g #\h #\t)]
    [(and (>= b 20) (< b 25))(string #\n #\o #\r #\m #\a #\l)]
    [(and (>= b 25) (< b 30))(string #\o #\b #\e #\s #\e #\1)]
    [(and (<= 30 b) (< b 40))(string #\o #\b #\e #\s #\e #\2)]
    [else (string #\o #\b #\e #\s #\e #\3)]))

(define (bmi w h)
  (print_bmi
    (/ w (* h h))))

;;Factorial
(define (factorial n)
    (cond
      [(< n 1) 1]
      [else (* n (factorial (- n 1)))]))

;;Duplicate
(define (duplicate lst)
  (cond
    [(empty? lst) '() ]
    [else (append (list (car lst) (car lst)) (duplicate (cdr lst)))]))

;;POW

(define (pow a b)
  (cond
    [(eq? b 0) 1]
    [else (* a (pow a (- b 1)))]))

;;FIB
(define (fib n)
    (cond
      [(< n 3) 1]
      [else (+ (fib (- n 1)) (fib (- n 2)))]))

;;Enlist
(define (enlist lst)
  (cond
    [(empty? lst) '() ]
    [else (cons (list (car lst)) (enlist (cdr lst)))]))

;;Add-list
(define (add-list lst)
  (cond
    [(empty? lst) 0 ]
    [else (+ (car lst) (add-list (cdr lst)))]))

;;Invert Pairs
(define (invert-pairs lst)
  (cond
    [(empty? lst) '()]
    [else (cons (append (cdr (car lst)) (list(car(car lst))) )(invert-pairs (cdr lst)) )]))

;;List of Symbols
(define (list-of-symbols? lst)
  (cond
    [(empty? lst) #t]
    [else (and (not (number? (car lst))) (list-of-symbols? (cdr lst)))]))

;;Swapper
(define (swapper a b lst)
  (cond
    [(empty? lst) '()]
    [(eq? a (car lst)) (cons b (swapper a b (cdr lst)))]
    [(eq? b (car lst)) (cons a (swapper a b (cdr lst)))]
    [else (cons (car lst) (swapper a b (cdr lst)))]))









