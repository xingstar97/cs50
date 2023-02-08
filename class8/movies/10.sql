SELECT name FROM people, movies, directors, ratings
WHERE movies.id = directors.movie_id
AND people.id = directors.person_id
AND movies.id = ratings.movie_id
AND rating >=9.0
GROUP BY people.id