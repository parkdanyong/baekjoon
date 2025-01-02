'''
    용도 / 세부 설명 / 예시

    데이터 저장,검색 / 빠른 조회 및 저장 / 해시 테이블, 데이터베이스, 캐시

    데이터 무결성 / 데이터 변조 여부 확인 /파일 무결성 체크, 블록체인

    보안/인증 / 비밀번호 해시화, 서명 검증 / SHA-256 비밀번호 저장, 디지털 서명

    네트워크,암호화 / 안전한 통신, 데이터 전송 검증 / HTTPS, TLS/SSL

    문제 해결,알고리즘 / 효율적인 탐색 및 최적화 / 중복 탐지, 교집합 문제



    단순히 상수를 곱하거나 작은 정수를 곱하면, 입력값의 패턴이 해시 값에 고스란히 반영될 가능성이 큽니다
    소수는 다른 숫자들과의 공통 배수가 적기 때문에, 동일한 패턴의 입력값이 해시 함수에 들어왔을 때도 결과값이 균일하게 분산됩니다.
'''



def simpleHash(inputData, fixed_size=8) :
    hash_value = 0
    prime = 31  # 소수 값을 곱해 충돌을 줄임
    
    for char in inputData :
        # ord(): returns the ASCII or Unicode value of a specific character.
        hash_value = (hash_value * prime + ord(char)) % (10 ** fixed_size) 

    # zfill(): supports returning 0 to fit the length of a string to a specific length.
    return str(hash_value).zfill(fixed_size)



def bitwise_fixed_length_hash(input_string, bit_size=32):
    hash_value = 0
    for char in input_string:
        hash_value ^= ord(char)  # XOR 연산으로 문자값 추가
        hash_value = (hash_value * 31) & ((1 << bit_size) - 1)  # 비트 크기 제한
    
    return hash_value




def flexibleHash(input_string, fixed_size=8, prime=31):
    hash_value = 0
    for char in input_string:
        hash_value = (hash_value * prime + ord(char)) % (10 ** fixed_size)
    return str(hash_value).zfill(fixed_size)


